#include <stdio.h>

/**
 * print_diagsums - print the sum of the two diagonals
 *	of a square matrix of integers
 * @a: Pointer to 2D arrays
 * @size: Size of array
 */

void print_diagsums(int *a, int size)
{
	int i, left_diag = 0, right_diag = 0;

	for (i = 0; i < size; i++)
		left_diag += *(a + (i * (size + 1)));

	for (i = 1; i <= size; i++)
		right_diag += *(a + (i * (size - 1)));

	printf("%d, %d\n", left_diag, right_diag);
}

