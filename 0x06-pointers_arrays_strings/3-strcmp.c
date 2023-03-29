int _strlen(char *s);

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second strign
 *
 * Return:
 *	0, if the s1 and s2 are equal
 *	a negative value if s1 is less than s2
 *	a positive value if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0, n1 = 0, n2 = 0;

	while (s1[i++] != '\0')
		n1 += s1[i];

	i = 0;

	while (s2[i++] != '\0')
		n2 += s2[i];

	if (n1 < n2)
	{
		return (-15);
	}
	else if (n1 > n2)
	{
		return (15);
	}
	else
		return (0);

}

/**
 * _strlen - count length of string
 * @s: string
 *
 * Return: length of s
 */

int _strlen(char *s)
{
	char *ptr = s, len = 0;

	while (*ptr != '\0')
	{
		len++;
		ptr++;
	}

	return (len);
}

