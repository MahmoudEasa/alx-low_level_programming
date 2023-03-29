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
	int i, is_strcmp = 0, s1_len = _strlen(s1), s2_len = _strlen(s2);

	if (s1_len < s2_len)
		is_strcmp = -15;
	else if (s1_len > s2_len)
		is_strcmp = 15;
	else
	{
		for (i = 0; i < s1_len; i++)
		{
			if (s1[i] < s2[i])
			{
				is_strcmp = -15;
				break;
			}
			else if (s1[i] > s2[i])
			{
				is_strcmp = 15;
				break;
			}
		}
	}

	return (is_strcmp);
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

