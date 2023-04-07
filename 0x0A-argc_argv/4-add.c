#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 * @argc: The count of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i, j, len, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		len = strlen(argv[i]);

		for (j = 0; j < len; j++)
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
	}

	if (argc == 2)
		printf("%d\n", atoi(argv[1]));
	else
	{
		for (i = 1; i < argc; i++)
			sum += atoi(argv[i]);

		printf("%d\n", sum);
	}

	return (0);
}

