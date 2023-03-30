#include <string.h>

/**
 * leet - encodes a string into 1337
 * @s: string
 *
 * Return: pointer to string
 */

char *leet(char *s)
{
	char encode[10][10] = {
		{'a', 'A', 'e', 'E', 'o', 'O', 't', 'T', 'l', 'L'},
		{'4', '4', '3', '3', '0', '0', '7', '7', '1', '1'}
	};
	int i, j;

	for (i = 0; i < (int)strlen(s); i++)
		for (j = 0; j < 10; j++)
			if (s[i] == encode[0][j])
				s[i] = encode[1][j];
	return (s);
}

