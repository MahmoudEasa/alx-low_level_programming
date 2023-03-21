#include <stdio.h>

/**
 * print_times_table - Print the n times table starting with 0.
 * @n: number
 */

void print_times_table(int n)
{
	int i, j;

	if (n >= 0 && n <= 15)
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (j == 0)
					printf("%d", i * j);
				else
					printf("%3d", i * j);

				if (j == n)
					continue;
				printf(", ");
			}
			printf("\n");
		}
}

