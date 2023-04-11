#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *str_concat_helper(char *s1, char *s2);

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 *
 * Return: pointer to a newly allocated space in memory
 *	which contains the contents of s1,
 *	followed by the contents of s2, and null terminated
 *	or NULL if on failure
 *	or empty string if NULL is passed
 */

char *str_concat(char *s1, char *s2)
{
	char *ptr;

	if (!s1 && !s2)
	{
		ptr = malloc(1);

		if (ptr)
			ptr[0] = '\0';
	}
	else
	{
		ptr = str_concat_helper(s1, s2);
	}

	if (!ptr)
		return (NULL);

	return (ptr);
}

/**
 * str_concat_helper - allocated space in memory and concate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to a newly allocated space
 */

char *str_concat_helper(char *s1, char *s2)
{
	char *ptr, *ptr_helper;
	unsigned int s1_len = 0, s2_len = 0, sum;

	if (s1)
		s1_len = strlen(s1);
	if (s2)
		s2_len = strlen(s2);

	sum = s1_len + s2_len;

	ptr = (char *)malloc((sizeof(ptr)) * sum);
	ptr_helper = ptr;

	if (ptr)
	{
		if (s1)
			while (*s1)
			{
				*ptr_helper = *s1;
				ptr_helper++;
				s1++;
			}

		if (s2)
			while (*s2)
			{
				*ptr_helper = *s2;
				ptr_helper++;
				s2++;
			}

		*ptr_helper = '\0';
	}

	return (ptr);
}

