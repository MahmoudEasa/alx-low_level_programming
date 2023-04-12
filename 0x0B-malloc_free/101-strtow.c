#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char *remove_start_spaces(char *str);
void word_count(char *str, int *words);
void allocate_space_in_memory(int words, char **ptr,
		char *str, char *ptr_last);

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: pointer to an array of strings (words)
 *	or NULL if ((function fails) or (str == NULL or str == ""))
 */

char **strtow(char *str)
{
	char **ptr, *ptr_last;
	int str_len, words = 0;

	if (!str || (*str == ' ' && *(str + 1) == '\0'))
		return (NULL);

	/*Remove spaces from the start of the string*/
	if (*str == ' ')
		str = remove_start_spaces(str);

	if (*str == '\0')
		return (NULL);

	/*Remove spaces from the end of the string*/
	str_len = strlen(str) - 1;
	while (str_len > 0 && isspace(str[str_len]))
		str_len--;

	ptr_last = (str + str_len);

	/*Word count*/
	words++;
	word_count(str, &words);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));

	if (!ptr)
		return (NULL);

	/*Allocate space in memory*/
	allocate_space_in_memory(words, ptr, str, ptr_last);

	if (!ptr)
		return (NULL);

	return (ptr);
}

/**
 * remove_start_spaces - remove spaces from the start of the string
 * @str: String
 *
 * Return: pointer to the first character of the string
 */

char *remove_start_spaces(char *str)
{
	while (*str != '\0')
		if (*str == ' ')
			str++;
		else
			break;
	return (str);
}

/**
 * word_count - word count in string
 * @str: String
 * @words: word count
 */

void word_count(char *str, int *words)
{
	while (*str != '\0')
	{
		if (*str == ' ' && (*(str + 1) != ' ' && *(str + 1) != '\0'))
			*words += 1;
		else
		{
			str++;
			continue;
		}
		str++;
	}
}

/**
 * allocate_space_in_memory - Allocate space in memory
 * @words: count of words to allocate
 * @ptr: 2d array
 * @str: string
 * @ptr_last: last character in the string
 */

void allocate_space_in_memory(int words, char **ptr, char *str, char *ptr_last)
{
	int str_len = 0, i = 0, w = 0, w_help = 0, j = 0, word = 0;
	char *p_h = str;

	while (p_h <= ptr_last)
	{
		str_len++;
		p_h++;
	}

	for (j = 0; j < words; j++)
	{
		for (; i <= str_len + 1; i++)
		{
			if (str[i] != ' ' && str[i] != '\0')
				word++;
			else if ((str[i] == ' ' && str[i - 1] != ' ') || (str[i] == '\0'))
			{
				ptr[j] = (char *)malloc(sizeof(char) * word + 1);

				if (!ptr[j])
				{
					while (j > 0)
						free(ptr[--j]);

					free(ptr);
					return;
				}

				for (w = 0; w < word; w++)
				{
					ptr[j][w] = str[w_help];
					w_help++;
				}

				ptr[j][w] = '\0';
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
}

