#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main - generates random valid passwords for the program 101-crackme
 *
 * Return: Always 0
 */

int main(void)
{
	int n = 0;
	char c;

	srand(time(NULL));
	while (n <= 2645)
	{
		c = rand() % 128;
		n += c;
		putchar(c);
	}
	putchar(2772 - n);

	return (0);
}

