#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * print_strings - prints strings, followed by a new line
 * @separator: the string to be printed between the strings
 * @n: the number of strings passed to the function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list str;
	char *ptr;

	if (n)
	{
		va_start(str, n);
			for (i = 0; i < n; i++)
			{
				ptr = va_arg(str, char*);
				if (ptr)
					printf("%s", ptr);

				if (i == n - 1)
					continue;

				if (separator)
					printf("%s", separator);
			}
		va_end(str);
	}
	printf("\n");
}

