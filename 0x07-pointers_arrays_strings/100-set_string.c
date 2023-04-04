#include <stdio.h>

/**
 * set_string - set the value of a pointer to a char
 * @s: Pointer to pointer to string
 * @to: Pointer to string
 */

void set_string(char **s, char *to)
{
	*s = to;
}

