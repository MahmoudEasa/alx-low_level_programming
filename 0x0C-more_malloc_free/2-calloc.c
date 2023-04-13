#include <stdlib.h>
#include <stddef.h>

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number
 * @size: number
 *
 * Return: pointer to the allocated memory
 *	or NULL If (malloc fails or (nmemb or size is 0))
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (!ptr)
		return (NULL);

	for (i = 0; i < nmemb; i++)
		ptr[i] = (unsigned char)0;

	return (ptr);
}

