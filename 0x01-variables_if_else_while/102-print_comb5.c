#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int count1, count2;

	for (count1 = 0; count1 <= 98; count1++)
	{
		for (count2 = count1 + 1; count2 <= 99; count2++)
		{
			putchar((count1 / 10) + '0');
			putchar((count1 % 10) + '0');
			putchar(' ');
			putchar((count2 / 10) + '0');
			putchar((count2 % 10) + '0');

			if (count1 == 98 && count2 == 99)
				continue;

			putchar(',');
			putchar(' ');
		}
	}

	putchar('\n');
	return (0);
}

