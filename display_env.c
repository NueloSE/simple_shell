#include "main.h"
/**
 * display_env - function to display the enviornment
 *
 * @input: the right command.
 *
*/
void display_env(char *input)
{
	char *environment[ENV_MAX_SIZE];
	char *built_in = "env", **envir;
	int i = 0;
	int w;

	if (_strcmp(input, built_in) == 0)
	{
		envir = environ;

		while (envir[i] != NULL && i < ENV_MAX_SIZE - 1)
		{
			environment[i] = environ[i];
			i++;
		}
		environment[i] = NULL;

		for (w = 0; environment[w] != NULL; w++)
		{
			printf("%s\n", environment[w]);
		}
	}
}
