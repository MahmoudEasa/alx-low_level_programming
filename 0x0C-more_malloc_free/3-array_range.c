#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

/**
 * array_range - creates an array of integers
 * @min: number
 * @max: number
 *
 * Return: pointer to the newly created array
 *	or NULL if (malloc fails or min > max)
 */

int *array_range(int min, int max)
{
	int *ptr, i = 0;

	if (min > max)
		return (NULL);

	ptr = malloc(sizeof(*ptr) * ((max - min) + 1));

	if (!ptr)
		return (NULL);

	while (min <= max)
	{
		ptr[i++] = min;
		min++;
	}

	return (ptr);
}

