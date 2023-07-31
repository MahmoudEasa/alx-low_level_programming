#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: the index of the node
 *
 * Return: the nth node of a dlistint_t linked list or
 *	NULL if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp = head;
	unsigned int i = 0;

	if (index == 0)
		return (temp);

	while ((temp && i++ < index))
		temp = temp->next;

	return (temp);
}

