#include "main.h"

/**
 * _getenv - get the env variable specified at name
 * @name: the environmental variable
 * Return: pointer to the variable
*/

char *_getenv(const char *name)
{
	char **env, *sign;

	if (name == NULL || name[0] == '\0' || environ == NULL)
	{
		return (NULL);
	}
	for (env = environ; *env != NULL; env++)
	{
		sign = _strchr(*env, '=');

		if ((sign != NULL) &&
		((size_t)(sign - *env) == _strlen(name)) &&
		(_strncmp(*env, name, sign - *env) == 0))
		{
		return (sign + 1);
		}
	}
	return (NULL);
}

/**
 * char_count - counts the number of c in name
 * @name: the name of the string
 * @c: the character to count
 * Return: the number of times c occurs
*/

int char_count(char *name, int c)
{
	int i = 0, count = 0;

	for (; name[i]; i++)
	{
		if (name[i] == c)
		count++;
	}
	return (count);
}

/**
 * path_split - split a string into words
 * @name: string to split
 * Return: array of split words
*/

char **path_split(char *name)
{
	char **dir = NULL;
	char *token = NULL, *name_cpy = _strdup(name);
	int idx = 0;

	dir = malloc(sizeof(char *) * (char_count(name, ':') + 1));

	token = strtok(name_cpy, ":");
	while (token != NULL)
	{
		dir[idx] = _strdup(token);
		token = strtok(NULL, ":");
		idx++;
	}
	dir[idx] = NULL;
	return (dir);
}

/**
 * path_finder - finds a function complete path
 * @name: function to find complete path
 * Return: 0 on succes. Otherwise -1
*/

int path_finder(char **name)
{
	struct stat *statbuff = malloc(sizeof(struct stat));
	char cwd[1024], **dirs;
	int i;

	dirs = path_split(_getenv("PATH"));
	getcwd(cwd, sizeof(cwd));

	if (*name[0] != '/')
	{
		for (i = 0; dirs[i]; i++)
		{
		chdir(dirs[i]);
		if (stat(*name, statbuff) == 0)
		{
			dirs[i] = _realloc(dirs[i], _strlen(dirs[i]),
			(_strlen(dirs[i]) + 2 + _strlen(*name) + 1));
			dirs[i] = _strcat(dirs[i], "/");
			*name = _strdup(strcat(dirs[i], *name));
			free(statbuff);
			for (i = 0; dirs[i]; i++)
				free(dirs[i]);
			free(dirs);
			chdir(cwd);
			return (0);
		}
		}
		chdir(cwd);
	}
	free(statbuff);
	return (0);
}
