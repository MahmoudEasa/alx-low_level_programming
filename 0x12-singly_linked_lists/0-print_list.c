#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: struct
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	int size = 0;
	const list_t *ptr = h;

	if (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");

		while (ptr)
		{
			if (ptr->str)
				printf("[%d] %s\n", ptr->len, ptr->str);

			ptr = ptr->next;
			size++;
		}
	}
	return (size);
}

