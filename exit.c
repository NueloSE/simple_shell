#include "main.h"

/**
 * myExit - ends the shell
 * @input: the commandline input
 * Return: void
*/

void myExit(char *input)
{
	char *built_in = "exit";

	if (_strcmp(input, built_in) == 0)
	{
		free(input);
		exit(EXIT_FAILURE);
	}
}
