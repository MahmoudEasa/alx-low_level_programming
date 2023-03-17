#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	int count1 = (int)'0';
	int count2 = count1;
	int count3 = count1;
	int count4 = count1 + 1;
	int count_stop = (int)'9';

	while (count1 <= count_stop)
	{
		while (count2 <= count_stop)
		{
			while (count3 <= count_stop)
			{
				while (count4 <= count_stop)
				{
					putchar((char)count1);
					putchar((char)count2);
					putchar(' ');
					putchar((char)count3);
					putchar((char)count4);
					putchar(',');
					putchar(' ');
					count4++;
				}
				count3++;
				count4 = (int)'0';
			}
			count2++;
			count3 = count1;
			count4 = count2 + 1;
		}
		count1++;
		count2 = (int)'0';
		count3 = count1;
		count4 = count2 + 1;
	}
	putchar((char)10);
	return (0);
}

