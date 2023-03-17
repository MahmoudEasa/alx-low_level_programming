#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Secces]
 */

int main(void)
{
	for (int c = (int)'a'; c <= (int)'z'; c++)
		putchar((char)c);
	putchar((char)10);

	return (0);
}
