#include <stdio.h>
#include <ctype.h>

void print(char *b, int size);

/**
 * print_buffer - print a buffer
 * @b: pointer to buffer
 * @size: buffer length
 */

void print_buffer(char *b, int size)
{
	if (size <= 0)
	{
		printf("\n");
		return;
	}
	else
		print(b, size);

}

/**
 * print - print a buffer
 * @b: pointer to buffer
 * @size: buffer length
 */

void print(char *b, int size)
{
	int i = 0, bytes = 1, pos = 0;

	while (i < size)
	{
		printf("%08x: ", i);

		while (bytes <= 10)
		{
			if (pos < size)
				printf("%02x", *(b + pos));
			else
				printf("%c%c", 32, 32);

			if (bytes % 2 == 0)
				printf(" ");
			pos++;
			bytes++;
		}
		pos = i;
		bytes = 1;

		while (bytes <= 10)
		{
			if (pos >= size)
			{
				printf("\n");
				break;
			}

			if (isprint(*(b + pos)))
				printf("%c", *(b + pos));
			else
				printf(".");

			if (bytes == 10)
				printf("\n");

			pos++;
			bytes++;
		}
		i += bytes - 1;
		pos = i;
		bytes = 1;
	}
}
