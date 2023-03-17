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
	int count3 = count2 + 1;
	int count_stop = (int)'9';

	while (count1 <= count_stop)
	{
		while (count2 <= count_stop)
		{
			while (count3 <= count_stop)
			{
				putchar((char)count1);
				putchar((char)count2);
				putchar((char)count3);
				if (count1 < count_stop - 2)
				{
					putchar(',');
					putchar(' ');
				}
				count3++;
			}
			count2++;
			count3 = count2 + 1;
		}
		count1++;
		count2 = count1 + 1;
		count3 = count2 + 1;
	}
	putchar((char)10);
	return (0);
}

