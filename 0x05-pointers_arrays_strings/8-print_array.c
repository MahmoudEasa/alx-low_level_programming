#include <stdio.h>

/**
 * print_array - print n elements of an array of integers,
 * followed by a new line
 * @a: (int) pointer of array
 * @n: the number of elements of the array to be printed
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i == (n - 1))
			continue;
		printf(", ");
	}

	printf("\n");
}

