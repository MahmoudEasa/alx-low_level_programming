#include <stdio.h>

/**
 * main - Entry Point
 *
 * Return: Always (0)
 */

int main(void)
{
	unsigned int num1, num2, temp;
	int i;

	for (i = 1; i < 50; i++)
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
		printf("%d", num1);
		if (i == 49)
			continue;
		printf(", ");
	}
	printf("\n");
	return (0);
}

