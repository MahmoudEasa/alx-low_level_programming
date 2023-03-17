#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int c_lower = (int)'a', c_upper = (int)'A';

	while (c_lower <= (int)'z')
	{
		putchar((char)c_lower);
		c_lower++;
	}
	while (c_upper <= (int)'Z')
	{
		putchar((char)c_upper);
		c_upper++;
	}

	putchar((char)10);

	return (0);
}
