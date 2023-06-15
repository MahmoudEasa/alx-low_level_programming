#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the head of the list
 * @idx: the index of the list where the new node should be added
 * @n: integer
 *
 * Return: the address of the new node, or NULL if it failed
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *temp = *h, *new_node = NULL;
	unsigned int i = 0;

	if (h)
	{
		new_node = (dlistint_t *)malloc(sizeof(dlistint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;

		if (idx == 0)
		{
			new_node->next = *h;
			if (*h)
				(*h)->prev = new_node;
			*h = new_node;
			return (new_node);
		}
		while ((temp && i++ < idx - 1))
			temp = temp->next;
		if (temp)
		{
			new_node->next = temp->next;
			new_node->prev = temp;
			temp->next->prev = new_node;
			temp->next = new_node;
		}
	}

	return (new_node);
}

