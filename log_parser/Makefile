default: build

parse.o: parse.cpp
	g++ -c parse.cpp

build: parse.o
	g++ -O3 parse.o -o parse

.PHONY: clean
clean:
	rm -f *.o
	rm -f parse
	rm -f report.csv
