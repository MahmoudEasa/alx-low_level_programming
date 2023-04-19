#include <stddef.h>

/**
 * array_iterator - executes a function given as a parameter on
 *	each element of an array
 * @array: array
 * @size: the size of the array
 * @action: pointer to the function you need to use
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array)
		for (i = 0; i < size; i++)
			action(array[i]);
}

