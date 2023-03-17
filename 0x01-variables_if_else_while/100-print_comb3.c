#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int count1 = (int)'0';
	int count2 = count1 + 1;

	while (count1 <= (int)'9')
	{
		while (count2 <= (int)'9')
		{
			putchar((char)count1);
			putchar((char)count2);
			if (count1 < (int)'8')
			{
				putchar(',');
				putchar(' ');
			}
			count2++;
		}
		count1++;
		count2 = count1 + 1;
	}
	putchar((char)10);
	return (0);
}

