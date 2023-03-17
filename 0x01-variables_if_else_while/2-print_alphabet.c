#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int c = (int)'a';

	while (c <= (int)'z')
	{
		putchar((char)c);
		c++;
	}

	putchar((char)10);

	return (0);
}

