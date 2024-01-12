#include "main.h"

/**
 * main - entry point of the program
 * @ac: variadic argument count
 * @av: variadic list of command line argument
 * @env: array of global variables
 * Return: 0 on success. otherwise -1
*/

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *input = NULL, **args, *path;
	size_t len = 0, arg_count, interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode)
			write(1, "$ ", 3);
		if (getline(&input, &len, stdin) == -1)
			break;
		input[_strcspn(input, "\n")] = '\0';

		myExit(input);
		display_env(input);

		tokenize_input(&args, input, &arg_count);
		if (_strcmp(input, "env") != 0)
		{
			if (arg_count > 0)
			{
				path = _getenv(env, "PATH");
				find_path(&args[0], path);
				if (file_access(args[0]) == 0)
				{
					execute_func(args, env);
				}
				else
				{
					free_array(args);
					perror(av[0]);
				}
			}
		}
	}
	if (interactive_mode)
		write(1, "\n", 1);
	free(input);
	exit(EXIT_SUCCESS);
}
