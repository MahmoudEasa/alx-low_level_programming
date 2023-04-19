#include "3-calc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	int num1, num2, result;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	if ((*argv[2] != '+' && *argv[2] != '-' && *argv[2] != '*'
				&& *argv[2] != '/' && *argv[2] != '%') || (*(argv[2] + 1) != '\0'))
	{
		printf("Error\n");
		exit(99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	op = argv[2];

	if ((*op == '/' && (num1 <= 0 || num2 <= 0)) || (*op == '%'
				&& (num1 <= 0 || num2 <= 0)))
	{
		printf("Error\n");
		exit(100);
	}


	result = (*get_op_func(op))(num1, num2);
	printf("%d\n", result);

	return (0);
}

