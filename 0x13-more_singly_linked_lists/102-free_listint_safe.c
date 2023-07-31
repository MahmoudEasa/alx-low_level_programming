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
	listint_t *ptr;
	listint_t *arr[1024];
	int count = 0, i;

	while (*h)
	{
		for (i = 0; i < count; i++)
			if (arr[i] == *h)
			{
				*h = NULL;
				return (count);
			}

		arr[count] = *h;
		count++;
		ptr = (*h)->next;
		free(*h);
		*h = ptr;
	}

	return (count);
}

