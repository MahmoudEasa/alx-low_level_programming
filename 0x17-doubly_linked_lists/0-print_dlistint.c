#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: the number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	size_t len = 0;

	while (ptr)
	{
		len++;
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}

	return (len);
}

