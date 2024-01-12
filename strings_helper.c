#include "main.h"

/**
 * _strlen - computes the length of a string
 * @str: the string
 * Return: length of str on success. Otherwise 0
*/

size_t _strlen(const char *str)
{
	size_t count;

	if (str == NULL)
		return (0);
	for (count = 0; str[count]; count++)
		;
	return (count);
}

/**
 * _strcpy - copy one string to another
 * @dest: destination string
 * @src: string to copy from
 * Return: pointer to newly copied string dest on success. Otherwise NULL
*/

char *_strcpy(char *dest, const char *src)
{
	char *dest_start;

	if (dest == NULL || src == NULL)
		return (NULL);

	dest_start = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string on success. Otherwise NULL
*/

char *_strdup(const char *str)
{
	char *copy;
	size_t length;

	if (str != NULL)
	{
		length = _strlen(str);
		copy = malloc((length + 1) * sizeof(char));

		if (copy == NULL)
			return (NULL);
		_strcpy(copy, str);
		return (copy);
	}
	return (NULL);
}

/**
 * _strchr - find the first occurence of a character in a string
 * @str: the string
 * @character: the target character
 * Return: pointer to the character on success. Otherwise NULL
*/

char *_strchr(const char *str, int character)
{
	if (str != NULL)
	{
		while (*str != '\0' && *str != character)
			str++;
		if (*str == character)
			return ((char *) str);
	}
	return (NULL);
}

/**
 * _strncmp - compares n bytes of string1 and string2
 * @n: number of bytes to compare
 * @str1: string1
 * @str2: string2
 * Return: 0 if str1 equals str2. otherwise the difference btw str1 and str2
*/

int _strncmp(const char *str1, const char *str2, size_t n)
{
	if (str1 == NULL && str2 == NULL)
		return (0);

	while (n != 0 && *str1 != '\0' && *str2 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
		return (0);
	return ((unsigned char)(*str1) - (unsigned char)(*str2));

}

