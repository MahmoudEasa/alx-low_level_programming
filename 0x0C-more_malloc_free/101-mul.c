#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef struct multiplynode
{
	char data;
	struct multiplynode *next;
	struct multiplynode *prev;
}MultiplyNode;

typedef struct myltiply
{
	int size;
	MultiplyNode *top;
	MultiplyNode *end;
}Multiply;

int _isdigit(char *s);
void create_node(Multiply *pm);
void _push(char c, Multiply *pm);
void multiply_nums(char *arg1, char *arg2,
	Multiply *pm, MultiplyNode *p_h, int s1_len, int s2_len);
void multiply_first_num(char *arg1, char *arg2, Multiply *pm,
	int s1_len, int s2_len);

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
	int s1_len, s2_len, i;
	Multiply m;
	MultiplyNode *p_h = NULL;

	if ((argc != 3) || (!_isdigit(argv[1]) || !_isdigit(argv[2])))
	{
		printf("Error\n");
		exit(98);
	}

	arg1 = argv[1];
	arg2 = argv[2];
	s1_len = strlen(arg1);
	s2_len = strlen(arg2);

	/*if the tow numbers <= 9999 multiply them
	if (s1_len <= 4 && s2_len <= 4)
	{
		printf("%d\n", (atoi(arg1) * atoi(arg2)));
		return (0);
	}*/

	/*Create Node*/
	create_node(&m);

	/*multiplies two positive numbers*/
	multiply_first_num(arg1, arg2, &m, s1_len, s2_len);
	printf("\nsize: %d top: %c end: %c\n", m.size, m.top->data, m.end->data);
	(void)p_h;
	multiply_nums(arg1, arg2, &m, p_h, s1_len, s2_len);
	printf("\nsize: %d top: %c end: %c\n", m.size, m.top->data, m.end->data);


	p_h = m.top;

/*	printf("\nsize: %d top: %c end: %c\n", m.size, m.top->data, m.end->data);*/
(void)i;	
	while (p_h)
	{
		printf("%c", p_h->data);
		printf("\nmtop: %c\n", m.top->data);
		p_h = p_h->next;
	}

	printf("\n");
	while (m.top != NULL)
	{
		p_h = m.top;
		m.top = m.top->next;
		free(p_h);
	}

	return (0);
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
 * @
 * @
 */

void multiply_first_num(char *arg1, char *arg2, Multiply *pm,
	int s1_len, int s2_len)
{
	int i, mul, remainder = 0;

	for (i = s1_len - 1; i >= 0; i--)
	{
		mul = (((arg2[s2_len - 1]) - '0') * (arg1[i] - '0'));

		mul += remainder;

		remainder = 0;

		if (mul <= 9)
			_push((mul + '0'), pm);
		else
		{
			remainder = mul / 10;
			_push(((mul % 10) + '0'), pm);
		}
	}

	if (remainder > 0)
		_push((remainder + '0'), pm);

}

/**
 * multiply_nums - multiply numbers
 * @
 * @
 */

void multiply_nums(char *arg1, char *arg2, Multiply *pm,
	MultiplyNode *p_h, int s1_len, int s2_len)
{
	int i, j, z, mul, remainder = 0;
	int zero = 1, sum = 0;
	MultiplyNode *p_helper = NULL;

	p_h = pm->end;
	for (i = s2_len - 2; i >=0; i--)
	{
		printf("\nzero: %d\n", zero);
		for (z = 0; z < zero; z++)
		{
			printf("\nph_pefore: %c\n", p_h->data);
			p_h = p_h->prev;
			printf("\nph_after: %c\n", p_h->data);
		}
		sum = (p_h->data - '0');


		for (j = s1_len - 1; j >= 0; j--)
		{
			mul = ((arg2[i] - '0') * (arg1[j] - '0'));


			sum += mul;
			printf("\nph_pefore: %c sum: %d, mul: %d\n", p_h->data, sum, mul);


			if (sum <= 9)
			{
				p_h->data = (sum + '0');
				p_h = p_h->prev;
				sum = 0;
			}
			else
			{
				p_h->data = ((sum % 10) + '0');
				remainder = sum / 10;
				p_h = p_h->prev;
				p_helper = p_h;

				while ((p_h >= pm->top && remainder > 0))
				{
					p_h = p_helper;
					sum = ((p_h->data) - '0') + remainder;
					remainder = 0;

					if (sum <= 9)
					{
						p_h->data = (sum + '0');
						break;
					}
					else
					{
						p_h->data = ((sum % 10) + '0');
						remainder = sum / 10;

						if (p_h)
							p_h = p_h->prev;
					}
				}

				if (remainder > 0)
				{
					_push((remainder + '0'), pm);
					remainder = 0;
				}

			p_helper = p_helper->prev;
			p_h = p_helper;

			}
		}
		zero++;
		p_h = pm->end;
		printf("\n\n==========================\n\n");
	}
}

