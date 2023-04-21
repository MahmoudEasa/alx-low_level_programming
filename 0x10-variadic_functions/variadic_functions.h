#ifndef VARIADIC_FUNCTION_H
#define VARIADIC_FUNCTION_H
#include <stdarg.h>

/**
 * struct formats - handle format for printf
 * @op: operator
 * @f: pointer to function
 *
 * Description: handle format for printf
 */

typedef struct formats
{
	char *op;
	void (*f)(va_list);
} Formats;


int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_c(va_list val);
void print_i(va_list val);
void print_f(va_list val);
void print_s(va_list val);

#endif /* #ifndef VARIADIC_FUNCTION_H */

