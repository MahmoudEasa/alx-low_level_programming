#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: pointer to an array of strings (words)
 *	or NULL if ((function fails) or (str == NULL or str == ""))
 */

char **strtow(char *str)
{
	char **ptr, *ps = str;
	int str_len, i = 0, w = 0, w_help = 0, j = 0, words = 0, word = 0;

	if (!str || *str == '\0')
		return (NULL);

	str_len = strlen(str);

	/*Move pointer to first character in string*/

	for (i = 0; i < str_len; i++)
	{
		if (str[i] == ' ')
		{
			str_len--;
			ps++;
		}
		else
			break;
	}

	if (*ps == '\0')
		return (NULL);

	for (i = strlen(str) - 1; i >= 0; i--)
		if (str[i] == ' ')
			str_len--;
		else
			break;

	words++;

	for (i = 0; i < str_len; i++)
		if (ps[i] == ' ' && ps[i + 1] != ' ')
			words++;
		else
			continue;

	ptr = (char **)malloc(sizeof(char *) * (words + 1));

	if (!ptr)
		return (NULL);

	i = 0;
	for (j = 0; j < words; j++)
	{
		for (; i <= str_len; i++)
		{
			if (ps[i] != ' ')
				word++;
			else if (ps[i] == ' ' && ps[i - 1] != ' ')
			{
				ptr[j] = (char *)malloc(sizeof(char) * word + 1);

				for (w = 0; w < word; w++)
				{
					ptr[j][w] = ps[w_help];
					w_help++;
				}

				ptr[j][w_help] = '\0';
				w_help++;
				i++;
				word = 0;
				break;
			}
			else
				w_help++;
		}
	}

	ptr[i] = NULL;

	return (ptr);
}

