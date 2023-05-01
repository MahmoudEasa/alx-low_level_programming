#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to first element
 *
 * Return: the size of the list that was free’d
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *ptr, *next = (*h)->next;
	size_t count = 0;

	while ((*h && next && (next < ptr)))
	{
		ptr = (*h)->next;
		next = next->next;
		free(*h);
		*h = ptr;
		count++;
	}
	free(*h);
	*h = NULL;
	count++;

	return (count);
}

