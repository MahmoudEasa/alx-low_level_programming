#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_listint - sum of all the data (n) of a listint_t linked list
 * @head: pointer to first element
 *
 * Return: the sum or 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
	listint_t *ptr;
	int sum = 0;

	if (head)
	{
		ptr = head;

		while (ptr)
		{
			sum += ptr->n;
			ptr = ptr->next;
		}
	}

	return (sum);
}

