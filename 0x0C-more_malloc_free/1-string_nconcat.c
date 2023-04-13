#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number
 *
 * Return: pointer shall point to a newly allocated space in memory,
 *	which contains s1, followed by the first n bytes of s2, and null terminated
 *	or NULL if the function fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int i = 0, index = 0, len, s2_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";

	s2_len = strlen(s2);

	if (n < s2_len)
		len = (strlen(s1) + n) + 1;
	else
		len = (strlen(s1) + s2_len) + 1;

	ptr = malloc(sizeof(*s1) * len);

	if (!ptr)
		return (NULL);

	while (s1[index] != '\0')
	{
		ptr[index] = s1[index];
		index++;
	}

	while ((s2[i] != '\0' && i < n))
	{
		ptr[index] = s2[i];
		index++;
		i++;
	}
	ptr[index] = '\0';

	return (ptr);
}

