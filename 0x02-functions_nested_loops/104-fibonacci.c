#include <stdio.h>

/**
 * main - Entry Point
 *
 * Return: Always (0)
 */

int main(void)
{
	unsigned long n1 = 0, n2 = 1, temp;
	unsigned long n1_h1, n1_h2, n2_h1, n2_h2;
	unsigned long h1, h2;
	int i;

	for (i = 0; i < 92; i++)
	{
		temp = n1 + n2;
		printf("%lu, ", temp);
		n1 = n2;
		n2 = temp;
	}

	n1_h1 = n1 / 10000000000;
	n2_h1 = n2 / 10000000000;
	n1_h2 = n1 % 10000000000;
	n2_h2 = n2 % 10000000000;

	for (i = 93; i <= 98; i++)
	{
		h1 = n1_h1 + n2_h1;
		h2 = n1_h2 + n2_h2;

		if ((n1_h2 + n2_h2) > 9999999999)
		{
			h1 += 1;
			h2 %= 10000000000;
		}
		printf("%lu%lu", h1, h2);
		if (i != 98)
			printf(", ");

		n1_h1 = n2_h1;
		n1_h2 = n2_h2;
		n2_h1 = h1;
		n2_h2 = h2;
	}
	printf("\n");
	return (0);
}

