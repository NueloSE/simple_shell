#include "main.h"

/**
 * tokenize_input - splits a string of characters into seperate words
 * @args: a double pointer to command line argument passed
 * @input: the string of character
 * @arg_count: the number of argument in the string
 * Return: array of strings
*/

void tokenize_input(char ***args, char *input, size_t *arg_count)
{
	char *token;
	size_t token_count = char_count(input, ' ') + 1;

	*arg_count = 0;
	*args = malloc(sizeof(char *) * (token_count + 1));
	if (!*args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		(*args)[*arg_count] = _strdup(token);
		(*arg_count)++;
		token = strtok(NULL, " ");
	}
	(*args)[*arg_count] = NULL;
}

/**
 * file_access - checks if a file can be accessed an executable
 * @name: name of the file to check
 * Return: 0 on success. Otherwise -1
*/

int file_access(char *name)
{
	if (name == NULL)
		return (-1);
	return (access(name, F_OK | X_OK));
}
