#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * print_chessboard - print the chessboard
 * @a: Two dimensional (2D) arrays
 */

void print_chessboard(char (*a)[8])
{
	int i, j;

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			if (a[j][i] == ' ')
				break;
			_putchar(a[j][i]);
		}
		_putchar(10);
	}
}

