#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to first element
 * @n: int
 *
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ptr, *p_h = NULL;

	ptr = malloc(sizeof(ptr));

	if (!ptr)
		return (NULL);

	ptr->n = n;
	ptr->next = NULL;

	if (!*head)
		*head = ptr;
	else
	{
		p_h = *head;

		while (p_h->next)
			p_h = p_h->next;

		p_h->next = ptr;
	}

	return (ptr);
}

