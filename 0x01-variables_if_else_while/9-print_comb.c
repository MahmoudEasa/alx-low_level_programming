#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int c = (int)'0';

	while (c <= (int)'9')
	{
		putchar((char)c);

		if (c < (int)'9')
		{
			putchar(',');
			putchar(' ');
		}
		c++;
	}
	putchar((char)10);
	return (0);
}

