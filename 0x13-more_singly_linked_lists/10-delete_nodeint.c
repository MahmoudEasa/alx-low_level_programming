#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node
 *	at index of a listint_t linked list
 * @head: pointer to first element
 * @index: the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptr;
	unsigned int i = 0;

	if (*head && index == 0)
	{
		ptr = *head;
		*head = ptr->next;
		free(ptr);
		return (1);
	}

	ptr = *head;
	while ((ptr && i < index))
	{
		if (i++ == (index - 1))
		{
			delete(ptr);
			return (1);
		}
		ptr = ptr->next;
	}

	return (-1);
}

/**
 * delete - delete node
 * @head: pointer to the node to delete
 */

void delete(listint_t *head)
{
	listint_t *ptr;

	ptr = head->next;
	head->next = ptr->next;
	free(ptr);
}

