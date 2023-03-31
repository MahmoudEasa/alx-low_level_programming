#include <string.h>
#include <stdio.h>

void add_numbers(char *r, int *greater, int *less,
	int *rest, char *n1, char *n2);
void add_rest_numbers(char *r, int *greater, int *less,
	int *rest, char *n1, char *n2, int n1_len, int n2_len);

/**
 * infinite_add - adds two numbers
 * @n1: pointer to number1
 * @n2: pointer to number2
 * @r: the result
 * @size_r: the buffer size
 *
 * Return: pointer to the result
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int less, greater, rest = 0;
	int n1_len = strlen(n1);
	int n2_len = strlen(n2);

	if (n1_len > n2_len)
	{
		greater = n1_len;
		less = n2_len;
	}
	else
	{
		greater = n2_len;
		less = n1_len;
	}

	if (size_r <= n1_len + 1 || size_r <= n2_len + 1)
	{
		return (0);
	}
	else
	{
		*(r + greater + 1) = '\0';
		if (n1_len > n2_len)
			add_numbers(r, &greater, &less, &rest, n1, n2);
		else
			add_numbers(r, &greater, &less, &rest, n2, n1);
		add_rest_numbers(r, &greater, &less, &rest, n1, n2, n1_len, n2_len);
	}

	if (r[0] == '0')
	{
		int i, r_len = strlen(r);

		for (i = 0; i < r_len; i++)
			*(r + i) = *(r + (i + 1));
	}

	return (r);
}

/**
 * add_numbers - add numbers greater length = less length
 * @n1: pointer to number1
 * @n2: pointer to number2
 * @r: the result
 * @greater: greater length
 * @less: less length
 * @rest: rest of number
 */

void add_numbers(char *r, int *greater, int *less,
	int *rest, char *n1, char *n2)
{
	while (((*greater >= 0) && (*less >= 0)))
	{
		int num1 = *(n1 + (*greater - 1)) - '0';
		int num2 = *(n2 + (*less - 1)) - '0';
		int sum = (num1 + num2);

		if (*less == 0 && *greater > 0)
			break;

		if (*less == 0)
		{
			sum = *rest;
			*rest = 0;
		}

		if (*rest > 0)
		{
			sum += *rest;
			*rest = 0;
		}

		if (sum > 9)
		{
			sum += *rest;
			*rest = sum / 10;
			*(r + *greater) = ((sum % 10) + '0');
		}
		else
		{
			*(r + *greater) = (sum + '0');
		}
		*greater -= 1;
		*less -= 1;
	}
}

/**
 * add_rest_numbers - add rest of numbers greater length
 * @n1: pointer to number1
 * @n2: pointer to number2
 * @r: the result
 * @greater: greater length
 * @less: less length
 * @rest: rest of number
 * @n1_len: length of n1
 * @n2_len: lenght of n2
 */

void add_rest_numbers(char *r, int *greater, int *less, int *rest,
	       char *n1, char *n2, int n1_len, int n2_len)
{
	if (*greater > *less)
		while (*greater >= 0)
		{
			int num;

			if (n1_len > n2_len)
				num = *(n1 + (*greater - 1)) - '0';
			else
				num = *(n2 + (*greater - 1)) - '0';

			if (*greater == 0)
			{
				num = *rest;
				*rest = 0;
			}

			if (*rest > 0)
			{
				num += *rest;
				*rest = 0;
			}

			if (num > 9)
			{
				num += *rest;
				*rest = num / 10;
				*(r + *greater) = ((num % 10) + '0');
			}
			else
			{
				*(r + *greater) = (num + '0');
			}

			*greater -= 1;
		}
}

