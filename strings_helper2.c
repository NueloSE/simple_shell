#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: the final string to add another string
 * @src: the sorce to copy from
 * Return: a point to the concatenated string on success
*/

char *_strcat(char *dest, const char *src)
{
	char *result;

	if (dest == NULL || src == NULL)
		return (NULL);
	result = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}

/**
 * _strcspn - compute the first occurence of target in str
 * @str: the string to check
 * @target: the target character
 * Return: index of target on success. otherwise strlen + 1
*/

size_t _strcspn(const char *str, const char *target)
{
	size_t count = 0;
	const char *target_ptr;

	if (str == NULL || target == NULL)
		return (count);
	while (*str != '\0')
	{
		target_ptr = target;
		while (*target_ptr != '\0')
		{
			if (*str == *target_ptr)
				return (count);
			target_ptr++;
		}
		str++;
		count++;
	}
	return (count);
}

/**
 * _strcmp - compares 2 string
 * @str1: string 1
 * @str2: string 2
 * Return: the difference btw str1 and str2
*/

int _strcmp(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
