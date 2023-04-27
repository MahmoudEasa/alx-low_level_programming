#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: struct
 *
 * Return: the number of elements in a linked list_t list
 */

size_t list_len(const list_t *h)
{
	int size = 0;

	while (h)
	{
		size++;
		h = h->next;
	}

	return (size);
}

