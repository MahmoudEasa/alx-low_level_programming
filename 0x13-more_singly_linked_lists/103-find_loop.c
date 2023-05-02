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
	listint_t *ptr = head;
	listint_t *arr[1024];
	int count = 0, i;

	while (ptr)
	{
		for (i = 0; i < count; i++)
			if (arr[i] == ptr)
				return (ptr);

		arr[count] = ptr;
		count++;
		ptr = ptr->next;
	}

	return (NULL);
}

