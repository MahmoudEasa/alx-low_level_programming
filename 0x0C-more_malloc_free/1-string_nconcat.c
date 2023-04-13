#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

char *concat_helper(char *s1, char *s2, unsigned int n,
		unsigned int s1_len, unsigned int s2_len);

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
	unsigned int s1_len = 0, s2_len = 0;

	if (s1)
		s1_len = strlen(s1);
	if (s2)
		s2_len = strlen(s2);

	if (!s1 && !s2)
	{
		ptr = malloc(sizeof(*s1));
		if (!ptr)
			return (NULL);

		*ptr = '\0';
	}

	if (s1 && (!s2 || *s2 == '\0'))
	{
		return (s1);
	}
	else
		ptr = concat_helper(s1, s2, n, s1_len, s2_len);

	return (ptr);
}

/**
 * concat_helper - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number
 * @s1_len: s1 length
 * @s2_len: s2 length
 *
 * Return: pointer shall point to a newly allocated space in memory,
 *	which contains s1, followed by the first n bytes of s2, and null terminated
 *	or NULL if the function fails
 */

char *concat_helper(char *s1, char *s2, unsigned int n,
		unsigned int s1_len, unsigned int s2_len)
{
	unsigned int i = 0, sum, w = 0;
	char *ptr;

	if (n >= s2_len)
		sum = s1_len + s2_len + 1;
	else
		sum = s1_len + n + 1;

	ptr = malloc(sizeof(*s1) * sum);

	if (!ptr)
		return (NULL);

	if (s1_len > 0)
		for (; i < s1_len; i++)
			ptr[i] = s1[i];

	for (; i < sum; i++)
		ptr[i] = s2[w++];

	ptr[i] = '\0';

	return (ptr);
}

