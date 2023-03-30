#include <string.h>
#include <stdio.h>

/**
 * rot13 - encodes a string using rot13
 * @s: string
 *
 * Return: pointer to string
 */

char *rot13(char *s)
{
	int i = 0, j = 0;
	char encode[2][52]	= {
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"
	};

	while (*(s + i) != '\0')
	{
		while (encode[0][j] != '\0')
		{
			if (*(s + i) == encode[0][j])
			{
				*(s + i) = encode[1][j];
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}

	return (s);
}


