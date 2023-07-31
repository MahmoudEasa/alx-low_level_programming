#include <stdio.h>
#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *ptr = h;
	size_t len = 0;

	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}

	return (len);
}

