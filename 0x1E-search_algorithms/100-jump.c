#include "search_algos.h"
#include <math.h>

void print(size_t index, int value, int between);

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

	if (array[start] > value)
	{
		print(start, array[start], 0);
		return (-1);
	}

	sqr = sqrt(size);

	while (start < size)
	{
		end = start + sqr;
		print(start, array[start], 0);
		if ((array[end] >= value) || (end >= size))
		{
			print(start, (int)end, 1);
			for (; (start <= end && start < size); start++)
			{
				print(start, array[start], 0);
				if (array[start] == value)
					return (start);
			}
		}
		start = end;
	}

	return (-1);
}

/**
 * print - print checked array
 * @index: The index
 * @value: The value
 * @between: If between indexess message
 */

void print(size_t index, int value, int between)
{
	if (between)
		printf("Value found between indexes [%ld] and [%d]\n",
			index, value);
	else
	{
		printf("Value checked array[%ld]", index);
		printf(" = [%d]\n", value);
	}
}

