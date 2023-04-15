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

	/*if the tow numbers <= 9999 multiply them*/
	if (s1_len <= 4 && s2_len <= 4)
	{
		printf("numbers: %d\n", (atoi(arg1) * atoi(arg2)));
		return (0);
	}

	/*Create Node*/
	create_node(&m);

	/*multiplies two positive numbers*/
	multiply_nums(arg1, arg2, &m, p_h, s1_len, s2_len);

	p_h = m.top;

/*	printf("\nsize: %d top: %c end: %c\n", m.size, m.top->data, m.end->data);*/
(void)i;	
	for (i = 0; i < m.size; i++)
	{
		printf("%c", p_h->data);
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
 * _push - create new node
 * @c: character
 * @pm: pointer
 */

void multiply_nums(char *arg1, char *arg2, Multiply *pm,
	MultiplyNode *p_h, int s1_len, int s2_len)
{
	int i, j, z, mul, remainder = 0, remainder_sum = 0;
	int zero = 0, ones = 0, sum = 0;
	int greater = (s1_len > s2_len ? s1_len : s2_len);
	int less = (s1_len < s2_len ? s1_len : s2_len);

	for (i = less - 1; i >=0; i--)
	{
		printf("\nzero: %d\n", zero);
		if (zero > 0)
		{
			for (z = 0; z < zero; z++)
			{
				printf("\nph_pefore: %c\n", p_h->data);
				p_h = p_h->prev;
				printf("\nph_after: %c\n", p_h->data);
			}
			sum = (p_h->data - '0');
		}


		for (j = greater - 1; j >= 0; j--)
		{
			if (s1_len < s2_len)
				mul = ((arg1[i] - '0') * (arg2[j] - '0')) + remainder + remainder_sum;
			else
				mul = ((arg2[i] - '0') * (arg1[j] - '0')) + remainder + remainder_sum;

/*			printf("\nmul: %d zero: %d\n", mul, zero);*/

			remainder = 0;

			if (mul <= 9)
			{
				sum += mul + remainder_sum;
				remainder_sum = 0;

				if (sum <= 9)
				{
/*					printf("\nifsum<=9: %c\n", sum + '0');*/
					_push((sum + '0'), pm);
					sum = 0;
				}
				else
				{
					remainder_sum = sum / 10;
/*					printf("\nelsesum<=9: %c\n", (sum % 10) + '0');*/
					_push(((sum % 10) + '0'), pm);
					sum = 0;
				}
			}
			else
			{
				ones = mul % 10;
				remainder = mul / 10;
/*				printf("\nsum: %d\n", sum);*/
				sum += ones + remainder_sum;
				remainder_sum = 0;

/*				printf("\nones: %d remainder: %d sum: %d\n", ones, remainder, sum);*/

				if (sum <= 9)
				{
					/*printf("\nesleonesifsum<=9: %c\n", sum + '0');*/
					_push((sum + '0'), pm);
					sum = 0;
				}
				else
				{
					remainder_sum = sum / 10;
					/*printf("\nelseesleonesifsum<=9: %c\n", (sum % 10) + '0');*/
					_push(((sum % 10) + '0'), pm);
					sum = 0;
				}

			}
		}
/*		p_h = pm->top;
		while (p_h != NULL)
		{
			printf("\nph->data: %c\n", p_h->data);
			p_h = p_h->next;
		}
		printf("\nsum: %d\n", sum);*/
		zero++;
		p_h = pm->end;
		printf("==========================");
	}
}

