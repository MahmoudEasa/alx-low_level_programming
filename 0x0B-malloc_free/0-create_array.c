#include <stddef.h>
#include <stdlib.h>

/**
 * create_array - creates an array of chars,
 *	and initializes it with a specific char
 * @size: size of array
 * @c: character to store in array
 *
 * Return: pointer to the array, or NULL (if it fails or size = 0)
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	if (size <= 0)
		return (NULL);

	ptr = malloc((sizeof(*ptr)) * size);

	if (!ptr)
		return (NULL);

	for (i = 0; i < size; i++)
		ptr[i] = c;

	ptr[i] = '\0';

	return (ptr);
}

