#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index
 *	of a dlistint_t linked list
 * @head: pointer to the head of list
 * @index: the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *help;
	unsigned int i = 0;

	if (!head || !(*head))
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while ((temp && i++ < index - 1))
		temp = temp->next;

	if (temp && temp->next)
	{
		help = temp->next->next;
		if (help)
			help->prev = temp;
		free(temp->next);
		temp->next = help;
	}
	else
		return (-1);

	return (1);
}

