#include <stdio.h>
#include <stdlib.h>

int coins_count(int num);

/**
 * main - Entry point
 * @argc: The count of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int num;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num = atoi(argv[1]);

	if (num <= 0)
		printf("0\n");
	else
		printf("%d\n", coins_count(num));

	return (0);
}

/**
 * coins_count - count number of coins
 * @num: Number
 *
 * Return: Number of coins
 */

int coins_count(int num)
{
	int coins = 0;

	while (num > 0)
		if (num >= 25)
		{
			coins += num / 25;
			num %= 25;
		}
		else if (num >= 10)
		{
			coins += num / 10;
			num %= 10;
		}
		else if (num >= 5)
		{
			coins += num / 5;
			num %= 5;
		}
		else if (num >= 2)
		{
			coins += num / 2;
			num %= 2;
		}
		else
		{
			coins += num;
			num = 0;
		}

	return (coins);
}

