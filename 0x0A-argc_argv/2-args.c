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
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}

