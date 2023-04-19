#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: (0);
 */

int main(int argc, char **argv)
{
	int i, bytes;

	int (*opcode)() = &main;
	unsigned char *ptr = (unsigned char *)opcode;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(1);
	}

	for (i = 0; i < bytes; i++)
		printf("%.2x ", ptr[i]);

	printf("\n");
	return (0);
}

