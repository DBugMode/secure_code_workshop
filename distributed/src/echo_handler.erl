-module(echo_handler).
-behavior(cowboy_handler).
-include_lib("amqp_client/include/amqp_client.hrl").
-export([init/2]).

init(Req, State) ->
    %% Req = cowboy_req:reply(200, #{<<"content-type">> => <<"text/plain">>},
    %%                        <<"Hello Erlang!">>,
    %%                        Req0),
    %% TODO: req/reply via rabbit
    {ok, Req, State}.
