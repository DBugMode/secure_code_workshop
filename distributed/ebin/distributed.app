{application, 'distributed', [
	{description, "New project"},
	{vsn, "0.1.0"},
	{modules, ['distributed_app','distributed_sup','echo_handler','hello_handler']},
	{registered, [distributed_sup]},
	{applications, [kernel,stdlib,cowboy,amqp_client]},
	{mod, {distributed_app, []}},
	{env, []}
]}.