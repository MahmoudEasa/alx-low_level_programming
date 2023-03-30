/**
 * cap_string - capitalizes all words of a string
 * @s: string
 *
 * Return: pointer to string
 */

char *cap_string(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) >= 'a' && *(s + i) <= 'z')
			*(s + i) -= 32;

		while (1)
		{
			if (*(s + i) == '-')
			{
				i++;
				continue;
			}

			if (*(s + i) == '\0' || *(s + i) == '\n'
				       || (*(s + i) == ' ' || *(s + i) == ',')
				       || (*(s + i) == ';' || *(s + i) == '.')
				       || (*(s + i) == '!' || *(s + i) == '?')
				       || (*(s + i) == '"' || *(s + i) == '(')
				       || (*(s + i) == ')' || *(s + i) == '{')
				       || (*(s + i) == '}'))
				break;

			if (*(s + i) == '\t')
			{
				*(s + i) = ' ';
				break;
			}

			i++;
		}

		if (*(s + i) == '\0')
			break;
		i++;
	}

	return (s);
}

