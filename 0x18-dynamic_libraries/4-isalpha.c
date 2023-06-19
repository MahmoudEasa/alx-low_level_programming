#include "main.h"

/**
 * _isalpha - Check for alphabetic character
 * @c: Character
 *
 * Return: 1 if c is a letter, lowercase or uppercase 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= (int)'a' && c <= (int)'z') ||
		       (c >= (int)'A' && c <= (int)'Z'))
		return (1);
	else
		return (0);
}

