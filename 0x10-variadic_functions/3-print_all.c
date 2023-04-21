#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	va_list fr;
	Formats handle_f[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s}
	};
	int i = 0, j = 0;
	char *p = "";

	va_start(fr, format);
		while (format && (*(format + i)))
		{
			j = 0;

			while (j < 4 && (*(format + i) != *(handle_f[j].op)))
				j++;

			if (j < 4)
			{
				printf("%s", p);
				handle_f[j].f(fr);
				p = ", ";
			}

			i++;

		}

	printf("\n");
	va_end(fr);
}

/**
 * print_c - print character
 * @val: va_list type
 */

void print_c(va_list val)
{
	char c;

	c = va_arg(val, int);

	printf("%c", c);
}

/**
 * print_i - print integer
 * @val: va_list type
 */

void print_i(va_list val)
{
	int num;

	num = va_arg(val, int);

	printf("%d", num);
}

/**
 * print_f - print float
 * @val: va_list type
 */

void print_f(va_list val)
{
	float num;

	num = va_arg(val, double);

	printf("%f", num);
}

/**
 * print_s - print string
 * @val: va_list type
 */

void print_s(va_list val)
{
	char *ptr;

	ptr = va_arg(val, char *);

	if (!ptr)
	{
		printf("(nil)");
		return;
	}

	printf("%s", ptr);
}

