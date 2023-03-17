#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	char x_num = (int)'0';
	char x_char = (int)'a';
	char counter = 0;

	while (counter < 16)
	{
		if (counter <= 9)
		{
			putchar((char)x_num);
			x_num++;
		} else
		{
			putchar((char)x_char);
			x_char++;
		}
		counter++;
	}
	putchar((char)10);
	return (0);
}

