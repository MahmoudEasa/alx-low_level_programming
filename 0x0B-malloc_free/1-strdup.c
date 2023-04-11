#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *	which contains a copy of the string given as a parameter
 * @str: string
 *
 * Reutn: pointer to a new string which is a duplicate of the string str
 *	or NULL (if str = NULL or insufficient memory was available)
 */

char *_strdup(char *str)
{
	char *ptr;
	unsigned int str_len, i;

	if (!str)
		return (NULL);

	str_len = strlen(str);
	ptr = malloc((sizeof(*ptr)) * str_len);

	if (!ptr)
		return (NULL);

	for (i = 0; i <= str_len; i++)
		ptr[i] = str[i];

	return (ptr);
}

