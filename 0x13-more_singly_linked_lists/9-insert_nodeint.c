#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to first element
 * @idx: the index of the list where the new node should be added
 * @n: int
 *
 * Return: the address of the new node, or NULL if it failed
 *	or it is not possible to add the new node at index idx
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr, *new = NULL;
	unsigned int i = 0;

	if (!*head && idx == 0)
		new = insert(*head, idx, n);
	else
	{
		ptr = *head;
		while ((ptr && i < idx))
		{
			if (i++ == (idx - 1))
				new = insert(ptr, idx, n);

			ptr = ptr->next;
		}
	}

	return (new);
}

/**
 * insert - add new node
 * @ptr: pointer to insert after
 * @index: the index to insert
 * @n: int
 *
 * Return: pointer to the new node
 */

listint_t *insert(listint_t *ptr, unsigned int index, int n)
{
	listint_t *new;

	new = malloc(sizeof(new));

	if (!new)
		return (NULL);

	new->n = n;

	if (index > 0)
	{
		new->next = ptr->next;
		ptr->next = new;
	}
	else
	{
		new->next = ptr;
		ptr = new;
	}

	return (new);
}

