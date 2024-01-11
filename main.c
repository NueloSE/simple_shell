#include "main.h"

char **tokenize_input(char *input, size_t *arg_count);

/**
 * main - entry point of the program
 * @ac: variadic argument count
 * @av: variadic list of command line argument
 * Return: 0 on success. otherwise -1
*/

int main(int ac, char **av)
{
	char *input = NULL, **args;
	size_t len = 0;
	size_t arg_count;
	int interactive_mode = isatty(STDIN_FILENO);
	pid_t pid;

	(void)ac, (void)av;
	while (1)
	{
		if (interactive_mode)
		write(1, "$ ", 3);
		if (getline(&input, &len, stdin) == -1)
			break;
		input[_strcspn(input, "\n")] = '\0';

		myExit(input);
		args = tokenize_input(input, &arg_count);
		if (arg_count > 0)
		{
			path_finder(&args[0]);
			if (access(args[0], F_OK | X_OK) == 0)
			{
				pid = fork();

				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					execve(args[0], args, NULL);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
					wait(NULL);
			}
			else
				perror(av[0]);
		}
	}
	if (interactive_mode)
		write(1, "\n", 1);
	free(input);
	free(args);
	return (0);
}
