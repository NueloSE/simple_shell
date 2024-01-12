#include "main.h"

/**
 * execute_func - execute shell command
 * @args: an array of command line arguments passed
 * @env: an array of commandline variables
 * Return: always void
*/

void execute_func(char **args, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(args[0], args, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free_array(args);
	}
}

/**
 * isWhitespace - check if str is an empty string
 * @str: the string
 * Return: 0 if not empty. otherwise 1
*/

int isWhitespace(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\n')
			return (0);
		str++;
	}
	return (1);
}
