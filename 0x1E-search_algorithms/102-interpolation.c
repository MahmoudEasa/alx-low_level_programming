#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 *	of integers using the Interpolation search algorithm
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: return the first index where value is located or -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high, pos;

	if (!array || !size)
		return (-1);

	high = size - 1;

	while (low <= high)
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]));

		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
		{
			if (array[pos - 1] == value)
			{
				high = pos - 1;
				continue;
			}
			else
				return (pos);
		}

		if (array[pos] > value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}
