#include "search_algos.h"

/**
 * binary_search - searches for a value in a sorted array
 *	of integers using the Binary search algorithm
 * @array: a pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: return the first index where value is located or -1
 */

int binary_search(int *array, size_t size, int value)
{
	size_t start = 0, end = size - 1, i, mid;

	if (!array || !size)
		return (-1);

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		printf("Searching in array: ");
		for (i = start; i <= end; i++)
		{
			printf("%d", array[i]);
			if (i < end)
				printf(" ,");
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}

