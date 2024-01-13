#include "main.h"

/**
 * myExit - ends the shell
 * @input: the commandline input
 * @status: the exit status to be used
 * Return: void
*/

void myExit(char *input, int status)
{
	char *built_in = "exit";

	if (_strcmp(input, built_in) == 0)
	{
		free(input);
		exit(status);
	}
}
