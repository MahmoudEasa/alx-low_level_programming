#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to first element
 *
 * Return: The address of the node where the loop starts,
 *	or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *ptr = head, *next;

	if (!head)
		return (NULL);

	next = head->next;
	while ((ptr && next && (next < ptr)))
	{
		ptr = ptr->next;
		next = next->next;
	}

	if (next)
		return (next);

	return (NULL);
}

