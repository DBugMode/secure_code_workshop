#include <iostream>
#include <sstream>
#include <ostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <iterator>
#include <functional>
#include <unordered_map>
#include <set>
#include <chrono>
#include <dirent.h>

struct Report
{
  long unsigned int num_actors;
  long long num_invalid_actors;

  void print() {
    std::cout << "Found " << num_actors << " actors in "
              << "TODO" << " files"
              << std::endl;
    std::cout << num_invalid_actors << " made invalid requests"
              << std::endl;
  }
};

struct LogEntry
{
  std::string address;
  std::string method;
  std::string uri;
  std::string user_agent;
  int response_code;
};

struct InvalidEntry
{
  std::string address;
  std::string request;
};

using LogEntryCallback = std::function<void(LogEntry)>;
using InvalidEntryCallback = std::function<void(InvalidEntry)>;

struct Actor
{
  std::string address;
  std::vector<LogEntry> requests;
  std::vector<InvalidEntry> invalid_requests;
  std::set<std::string> user_agents;
  std::unordered_map<int, long long> response_code_to_count;

  void print() const {
    std::cout << address << std::endl;
    std::cout << requests.size() + invalid_requests.size() << " requests" << std::endl;
    std::cout << invalid_requests.size() << " invalid requests" << std::endl;
    std::cout << user_agents.size() << " unique user agents" << std::endl;
    std::cout << response_code_to_count.size() << " unique HTTP methods" << std::endl;
    std::cout << std::endl;
  }
};

using Actors = std::unordered_map<std::string, Actor>;

std::string join(std::vector<std::string> const& elements,
                 const char *const delimiter)
{
  std::ostringstream os;
  auto b = begin(elements);
  auto e = end(elements);

  if (b != e) {
    std::copy(b, prev(e), std::ostream_iterator<std::string>(os, delimiter));
    b = prev(e);
  }

  if (b != e) {
    os << *b;
  }

  return os.str();
}

static std::string get_user_agent(std::vector<std::string> parts)
{
  std::string user_agent;

  try {
    std::vector<std::string> range;
    if (parts.size() > 11) {
      std::copy(std::begin(parts) + 11,
                std::begin(parts) + parts.size(),
                back_inserter(range));
      user_agent = join(range, " ");
    }
  } catch (int n) {
    user_agent = "-";
  }

  return user_agent;
}

bool is_valid_method(std::string method)
{
  return method == "GET"
    || method == "POST"
    || method == "HEAD"
    || method == "OPTIONS"
    || method == "CONNECT"
    || method == "PUT";
}

bool is_valid_response_code(int response_code)
{
  return (response_code >= 100 && response_code < 600);
}

bool is_valid_request(std::string method, int response_code)
{
  return (is_valid_method(method) && is_valid_response_code(response_code));
}

int parse_response_code(std::string code)
{
  try {
    return std::stoi(code);
  } catch (std::invalid_argument e) {
    return 0;
  }
}

std::vector<std::string> collect_files(std::string path)
{
  std::vector<std::string> files;

  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir(path.c_str())) != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      if (!(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)) {
        files.emplace_back(path + "/" + ent->d_name);
      }
    }
    closedir(dir);
  }

  return files;
}

void process_file(std::string file,
                  LogEntryCallback success_callback,
                  InvalidEntryCallback error_callback)
{
  std::stringstream ss(file);
  std::ifstream in(ss.str());
  std::string line;

  while(getline(in, line)) {
    std::istringstream iss(line);
    std::string part;
    std::vector<std::string> parts;

    while (iss >> part) {
      parts.emplace_back(part);
    }

    auto method = parts[5].erase(0,1);
    auto response_code = parse_response_code(parts[8]);
    auto user_agent = get_user_agent(parts);

    if (!is_valid_request(method, response_code)) {
      error_callback(InvalidEntry{line});
      continue;
    }

    auto entry = LogEntry{parts[0], method, parts[6], user_agent, response_code};

    success_callback(entry);
  }
}

void process_files(std::vector<std::string> files,
                   LogEntryCallback success_callback,
                   InvalidEntryCallback error_callback)
{
  for (auto &&file : files) {
    process_file(file, success_callback, error_callback);
  }
}

LogEntryCallback add_request(Actors &actors) {
  return [&](auto entry) {
    auto actor = actors.find(entry.address);
    if (actor == actors.end()) {
      Actor new_actor;
      new_actor.address = entry.address;
      new_actor.requests.emplace_back(entry);
      new_actor.user_agents.emplace(entry.user_agent);
      actors.emplace(std::make_pair(entry.address, new_actor));
    } else {
      actor->second.address = entry.address;
      actor->second.requests.emplace_back(entry);
      actor->second.user_agents.emplace(entry.user_agent);
    }
  };
}

InvalidEntryCallback add_invalid_request(Actors &actors) {
  return [&](auto entry) {
    auto actor = actors.find(entry.address);
    if (actor == actors.end()) {
      Actor new_actor;
      new_actor.invalid_requests.emplace_back(entry);
      actors.emplace(std::make_pair(entry.address, new_actor));
    } else {
      actor->second.invalid_requests.emplace_back(entry);
    }
  };
}

Report create_report(const Actors &actors)
{
  auto num_invalid_actors = 0;

  for (auto const& actor : actors) {
    if (actor.second.invalid_requests.size() > 0) {
      ++num_invalid_actors;
    }

    actor.second.print();
  }

  return Report{actors.size(), num_invalid_actors};
}

int main(int argc, char **argv)
{
  std::string path = "samples";
  std::unordered_map<std::string, Actor> actors;
  auto t0 = std::chrono::high_resolution_clock::now();
  process_files(collect_files(path), add_request(actors), add_invalid_request(actors));
  auto report = create_report(actors);
  report.print();
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << " millis" << std::endl;
}
