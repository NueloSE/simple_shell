#include "main.h"

/**
 * _getenv - get the env variable specified at name
 * @name: the environmental variable
 * @env_var: a list of environment variables
 * Return: pointer to the variable
*/

char *_getenv(char **env_var, const char *name)
{
	char *sign;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	for (; *env_var != NULL; env_var++)
	{
		sign = _strchr(*env_var, '=');

		if ((sign != NULL) &&
		((size_t)(sign - *env_var) == _strlen(name)) &&
		(_strncmp(*env_var, name, sign - *env_var) == 0))
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

size_t char_count(char *name, char c)
{
	size_t count = 0;

	while (*name)
	{
		if (*name == c)
			count++;
		name++;
	}
	return (count);
}

/**
 * find_path - checks PATH if name(command) exits
 * @name: address of name of command
 * @path: an array of all the global variables
 * Return: 0 on success. Otherwise -1
*/

int find_path(char **name, char *path)
{
	char *cwd = getcwd(NULL, 0);
	char *token, *new_path;
	struct stat stat_buf;

	if (name == NULL || *name == NULL || path == NULL)
	{
		free(cwd);
		return (-1);
	}

	if ((*name)[0] != '/' && (*name)[0] != '.')
	{
		char *path_copy = _strdup(path);

		token = strtok(path_copy, ":");

		while (token != NULL)
		{
		chdir(token);
		if (stat(*name, &stat_buf) == 0)
		{
			new_path = malloc(_strlen(token) + 1 + _strlen(*name) + 1);
			_strcpy(new_path, token);
			_strcat(new_path, "/");
			_strcat(new_path, *name);
			free(*name);
			*name = new_path;
			chdir(cwd);
			free(path_copy);
			free(cwd);
			return (0);
		}
		chdir(cwd);
		token = strtok(NULL, ":");
		}
		free(path_copy);
	}

	free(cwd);
	return (1);
}
