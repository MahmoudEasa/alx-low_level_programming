#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0)
 */

int main(void)
{
	int i, sum = 1;

	for (i = 1; i < 1024; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("%d\n", sum);
	return (0);
}

