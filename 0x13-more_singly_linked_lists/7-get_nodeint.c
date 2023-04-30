#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer to first element
 * @index: index node
 *
 * Return: the nth node of a listint_t linked list
 *	or NULL if the node does not exist
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *ptr;
	unsigned int i = 0;

	if (!head)
		return (NULL);
	else if (index == 0)
		return (head);

	ptr = head;
	while ((i <= index && ptr))
	{
		if (i++ == index)
			return (ptr);

		ptr = ptr->next;
	}

	return (NULL);
}

