#include <stdio.h>
#include "main.h"

/**
 * flip_bits - returns the number of bits you
 *	would need to flip to get from one number to another
 * @n: number
 * @m: number
 *
 * Return: the number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flips = 0;
	unsigned long int num = n ^ m;

	while (num)
	{
		flips++;
		num &= num - 1;
	}

	return (flips);
}

