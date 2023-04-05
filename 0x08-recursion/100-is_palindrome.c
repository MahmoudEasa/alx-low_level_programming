#include <string.h>
#include <stdio.h>

int _is_palindrome_helper(char *start, char *end, int len);

/**
 * is_palindrome - check string is a palindrome
 * @s: String
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */

int is_palindrome(char *s)
{
	int s_len = strlen(s);

	if (s_len % 2 == 0)
		return (_is_palindrome_helper(s, (s + s_len - 1), (s_len / 2) - 1));
	else
		return (_is_palindrome_helper(s, (s + s_len - 1), (s_len / 2)));
}

/**
 * _is_palindrome_helper - check string is a palindrome
 * @start: pointer to start string
 * @end: pointer to end string
 * @len: length the half of string
 *
 * Return: 1 if a strign is a palindrome and 0 if not
 */

int _is_palindrome_helper(char *start, char *end, int len)
{
	int found = 1;

	if (*start != *end)
		return (0);

	if (len > 0)
		found = _is_palindrome_helper((start + 1), (end - 1), (len - 1));

	if (found == 1)
		return (1);
	else
		return (0);
}

