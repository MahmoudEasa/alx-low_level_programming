/**
 * _memcpy - copies memory area
 * @dest: memory area 1
 * @src: memory area 2
 * @n: size to copy
 *
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}

