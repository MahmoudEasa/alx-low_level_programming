#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	char c = (int)'a';

	while (c <= (int)'z')
	{
		if (c == (int)'q' || c == (int)'e')
		{
			c++;
			continue;
		}

		putchar((char)c);
		c++;
	}

	putchar((char)10);

	return (0);
}
