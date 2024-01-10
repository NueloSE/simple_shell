#include "main.h"

/**
 * tokenize_input - splits a string of characters into seperate words
 * @input: the string of character
 * @arg_count: the number of argument in the string
 * Return: array of strings
*/

char **tokenize_input(char *input, size_t *arg_count)
{
	char *token, **args = malloc(MAX_INPUT_SIZE * sizeof(char *));

	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	*arg_count = 0;
	token = strtok(input, " ");

	while (token != NULL)
	{
		args[*arg_count] = _strdup(token);
		(*arg_count)++;
		token = strtok(NULL, " ");
	}
	args[*arg_count] = NULL;

	return (args);
}
