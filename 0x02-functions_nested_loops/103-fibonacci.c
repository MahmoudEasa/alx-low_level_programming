#include <stdio.h>

/**
 * main - Entry Point
 *
 * Return: Always (0)
 */

int main(void)
{
	long num1, num2, temp, sum = 0;
	int i;

	for (i = 1; i <= 89; i++)
	{
		if (i > 2)
		{
			temp = num1;
			num1 += num2;
			num2 = temp;
		}
		else
		{
			num1 = i;
			num2 = i - 1;
		}

		if (num1 % 2 == 0 && num1 <= 4000000)
		{
			sum += num1;
		}
	}
	printf("%ld\n", sum);
	return (0);
}

