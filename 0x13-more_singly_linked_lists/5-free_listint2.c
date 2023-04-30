#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint2 - that frees a listint_t list
 * @head: pointer to first element
 */

void free_listint2(listint_t **head)
{
	listint_t *ptr, **p = head;

	while ((p && *head))
	{
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}
}

