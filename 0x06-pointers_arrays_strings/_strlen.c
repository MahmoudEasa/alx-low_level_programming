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

