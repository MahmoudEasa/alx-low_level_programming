#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array
 *	of integers using the Jump search algorithm
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: return the first index where value is located or -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t start = 0, end, sqr;

	if (!array || !size)
		return (-1);

	sqr = sqrt(size);

	while (start < size)
	{
		if (array[start] > value)
		{
			printf("Value checked array[%ld]", start);
			printf(" = [%d]\n", array[start]);
			return (-1);
		}

		end = start + sqr;
		printf("Value checked array[%ld]", start);
		printf(" = [%d]\n", array[start]);
		if ((array[end] >= value) || (end >= size))
		{
			printf("Value found between indexes [%ld] and [%ld]\n",
				start, end);
			for (; (start <= end && start < size); start++)
			{
				printf("Value checked array[%ld]", start);
				printf(" = [%d]\n", array[start]);
				if (array[start] == value)
					return (start);
			}
		}
		start = end;
	}

	return (-1);
}

