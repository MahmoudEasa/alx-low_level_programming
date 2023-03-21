#include "main.h"
#include <stdio.h>

/**
 * times_table -  print the 9 times table, starting with 0
 */

void times_table(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
				printf("%d", i * j);
			else
				printf("%2d", i * j);
			if (j == 9)
				continue;
			printf(", ");
		}
		printf("\n");
	}
}

