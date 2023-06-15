#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the head of the list
 * @n: integer
 *
 * Return: the address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;

	if (head)
	{
		new_node = (dlistint_t *)malloc(sizeof(dlistint_t *));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
	}

	return (new_node);
}

