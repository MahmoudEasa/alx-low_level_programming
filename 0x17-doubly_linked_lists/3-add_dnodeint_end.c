#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL, *temp = NULL;

	if (head)
	{
		new_node = (dlistint_t *)malloc(sizeof(dlistint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;

		temp = *head;
		while ((temp && temp->next))
			temp = temp->next;

		if (temp)
		{
			temp->next = new_node;
			new_node->prev = temp;
		}
		else
			*head = new_node;
	}

	return (new_node);
}

