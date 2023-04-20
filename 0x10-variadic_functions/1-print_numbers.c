#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * print_numbers - prints numbers, followed by a new line
 * @separator: the string to be printed between numbers
 * @n: the number of integers passed to the function
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list nums;

	if (n)
	{
		va_start(nums, n);
			for (i = 0; i < n; i++)
			{
				printf("%d", va_arg(nums, int));

				if (i == n - 1)
					continue;

				if (separator)
					printf("%s", separator);
			}
		va_end(nums);
	}
	printf("\n");
}

