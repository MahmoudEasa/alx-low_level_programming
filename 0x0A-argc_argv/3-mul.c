#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The count of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc > 1 && argc < 4)
		printf("%d\n", (atoi(argv[1]) * atoi(argv[2])));
	else
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}

