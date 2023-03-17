#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int num = 48;

	while (num <= 57)
	{
		putchar((char)num);
		num++;
	}
	putchar((char)10);

	return (0);
}
