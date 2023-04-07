#include <stdio.h>

/**
 * main - Entry point
 * @argc: The count of arguments
 * @argv: An array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argv[argc - 1])
		printf("%d\n", (argc - 1));

	return (0);
}

