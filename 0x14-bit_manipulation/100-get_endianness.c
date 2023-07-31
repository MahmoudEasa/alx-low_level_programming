#include <stdio.h>
#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	unsigned int val = 0x01020304;

	if (*(unsigned char *) &val == 0x04)
		return (1);

	return (0);
}

