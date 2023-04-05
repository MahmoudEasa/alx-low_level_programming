/**
 * _strlen_recursion - returns the length of a string
 * @s: String
 *
 * Return: Length of s
 */

int _strlen_recursion(char *s)
{
	int len;

	if (*s == '\0')
		return (0);

	len = 1 + _strlen_recursion((s + 1));

	return (len);
}

