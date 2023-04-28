#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to first element
 *
 * Return: the head node’s data (n)
 */

int pop_listint(listint_t **head)
{
	listint_t *ptr;
	int n = 0;

	if (*head)
	{
		n = (*head)->n;
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}

	return (n);

}

