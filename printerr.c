#include "main.h"

/**
 * printerr - handles printing error to standard error
 * @shellName: name of the shell program
 * @shellRunTime: the number of time the shell has ran
 * @cmdName: the name of the command
 * Return: Alway 127
*/

int printerr(char *shellName, int shellRunTime, char *cmdName)
{
	fprintf(stderr, "%s: %d: %s: not found\n",
	shellName, shellRunTime, cmdName);

	return (127);
}
