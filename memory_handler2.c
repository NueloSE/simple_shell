#include "main.h"

/**
 * _realloc - changes size of memory pointed to by ptr to size
 * @ptr: pointer to memory to resize
 * @old_size: the old size
 * @new_size: the new size
 * Return: always void pointer
*/

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *s, *aux;
	unsigned int a;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		s = malloc(new_size);
		if (s == NULL)
			return (NULL);

		return (s);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	s = malloc(new_size);
	if (s == NULL)
		return (NULL);

	aux = ptr;
	for (a = 0; a < old_size; a++)
		s[a] = aux[a];

	free(ptr);

	return (s);
}
