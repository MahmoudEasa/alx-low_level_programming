#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

/**
 * main - multiplies two positive numbers
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *arg1, *arg2;
	int s1_len, s2_len;
	Multiply m;

	if ((argc != 3) || (!_isdigit(argv[1]) || !_isdigit(argv[2])))
	{
		printf("Error\n");
		exit(98);
	}

	arg1 = argv[1];
	arg2 = argv[2];
	s1_len = strlen(arg1);
	s2_len = strlen(arg2);

	/* if the tow numbers <= 9999 multiply them */
	if (s1_len <= 4 && s2_len <= 4)
	{
		printf("%d\n", (atoi(arg1) * atoi(arg2)));
		return (0);
	}

	if (print_zero(arg1, arg2, s1_len, s2_len))
	{
		printf("0\n");
		return (0);
	}

	/*Create Node*/
	create_node(&m);

	/*multiplies two positive numbers*/
	multiply_first_num(arg1, arg2, &m, s1_len, s2_len);
	multiply_nums(arg1, arg2, &m, s1_len, s2_len);

	free_zero(&m);
	print(&m);
	free_nodes(&m);
	return (0);
}

/**
 * free_zero - free first zero of string
 * @pm: stack
 */

void free_zero(Multiply *pm)
{
	MultiplyNode *p_h;

	while (pm->top->data == '0')
	{
		p_h = pm->top;
		pm->top = pm->top->next;
		free(p_h);
	}
}

/**
 * _isdigit - check if the string includes a character
 * @s: string
 *
 * Return: 0 if true 1 if false
 */

int _isdigit(char *s)
{
	int i, s_len = strlen(s);

	for (i = 0; i < s_len; i++)
		if (s[i] < '0' || s[i] > '9')
			return (0);

	return (1);
}

/**
 * print_zero - print zero if the numpers are zero
 * @arg1: string
 * @arg2: string
 * @s1_len: length of arg1
 * @s2_len: length of arg2
 *
 * Return: 1 if (arg1 or arg2 = length of 0) else return 0
 */

int print_zero(char *arg1, char *arg2, int s1_len, int s2_len)
{
	int i, n1_found = 0, n2_found = 0;

	for (i = 0; i < s1_len; i++)
		if (arg1[i] != '0')
		{
			n1_found = 1;
			break;
		}

	for (i = 0; i < s2_len; i++)
		if (arg2[i] != '0')
		{
			n2_found = 1;
			break;
		}

	if (n1_found == 0 || n2_found == 0)
		return (1);

	return (0);
}

/**
 * create_node - initial node
 * @pm: pointer
 */

void create_node(Multiply *pm)
{
	pm->size = 0;
	pm->top = NULL;
	pm->end = NULL;
}

/**
 * _push - create new node
 * @c: character
 * @pm: pointer
 */

void _push(char c, Multiply *pm)
{
	MultiplyNode *pn = (MultiplyNode *)malloc(sizeof((pm + c)));

	if (!pn)
	{
		pm->top = NULL;
		pm->end = NULL;
		return;
	}

	pn->data = c;

	if (pm->size == 0)
	{
		pn->next = NULL;
		pn->prev = NULL;
		pm->end = pn;
		pm->top = pn;
	}
	else
	{
		pm->top->prev = pn;
		pn->next = pm->top;
		pn->prev = NULL;
		pm->top = pn;
	}
	pm->size++;
}

/**
 * multiply_first_num - multiply number
 * @arg1: string of numbers
 * @arg2: string of numbers
 * @pm: stack pointer to a node
 * @s1_len: the length of the string 1
 * @s2_len: the length of the string 2
 */

void multiply_first_num(char *arg1, char *arg2, Multiply *pm,
	int s1_len, int s2_len)
{
	int i, mul, remainder = 0;

	for (i = s1_len - 1; i >= 0; i--)
	{
		mul = (((arg2[s2_len - 1]) - '0') * (arg1[i] - '0')) + remainder;
		remainder = 0;

		remainder = mul / 10;
		_push(((mul % 10) + '0'), pm);
	}

	if (remainder > 0)
		_push((remainder + '0'), pm);
}

/**
 * multiply_nums - multiply numbers
 * @arg1: string of numbers
 * @arg2: string of numbers
 * @pm: stack pointer to a node
 * @s1_len: the length of the string 1
 * @s2_len: the length of the string 2
 */

void multiply_nums(char *arg1, char *arg2, Multiply *pm,
	int s1_len, int s2_len)
{
	int i, j, z, mul, remainder = 0;
	int zero = 1, data = 0;
	MultiplyNode *p_h = NULL;

	p_h = pm->end;
	for (i = s2_len - 2; i >= 0; i--)
	{
		for (z = 0; z < zero; z++)
			p_h = p_h->prev;

		for (j = s1_len - 1; j >= 0; j--)
		{
			if (p_h)
			{
				data = (p_h->data - '0');
			}
			else
				data = 0;

			mul = ((arg2[i] - '0') * (arg1[j] - '0')) + data + remainder;
			remainder = 0;

			if (p_h)
			{
				p_h->data = ((mul % 10) + '0');
				remainder = mul / 10;
				p_h = p_h->prev;
			}
			else
			{
				_push(((mul % 10) + '0'), pm);
				remainder = mul / 10;
				p_h = pm->top->prev;
			}
		}
		add_remainder(&remainder, pm);
		zero++;
		p_h = pm->end;
	}
}

/**
 * add_remainder - add remainder numbers
 * @remainder: number
 * @pm: pointer to stack
 */

void add_remainder(int *remainder, Multiply *pm)
{
	if (*remainder > 0)
	{
		if (*remainder <= 9)
			_push((*remainder + '0'), pm);
		else
		{
			_push(((*remainder % 10) + '0'), pm);
			_push(((*remainder / 10) + '0'), pm);
		}
		*remainder = 0;
	}
}

/**
 * print - print linked list
 * @pm: stack
 */

void print(Multiply *pm)
{
	MultiplyNode *p_h = pm->top;

	while (p_h)
	{
		printf("%c", p_h->data);
		p_h = p_h->next;
	}

	printf("\n");
}

/**
 * free_nodes - free the linked list
 * @pm: stack
 */

void free_nodes(Multiply *pm)
{
	MultiplyNode *p_h;

	while (pm->top)
	{
		p_h = pm->top;
		pm->top = pm->top->next;
		free(p_h);
	}
}

