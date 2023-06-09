/**
 * _strncpy - copies a string
 * @dest: first string
 * @src: second string
 * @n: number of strings to copy
 *	copy n bytes of src,
 *	to the buffer pointed to by dest
 *	if src length is equal to or greater than n copy all src
 *
 * Return: pointer to the resulting string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

