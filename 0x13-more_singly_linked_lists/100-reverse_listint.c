#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

void reverse(listint_t *temp, listint_t *last);

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to first element
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = *head, *last = NULL;

	if (head && *head && !(*head)->next)
		return (*head);

	while (temp != last)
	{
		if ((*head)->next != last)
			*head = temp->next;
		else
			break;
		reverse(temp, last);
		last = temp;
		temp = *head;
	}
	return (*head);
}

/**
 * reverse - reverse node
 * @temp: pointer to node
 * @last: pointer to the last node to stop
 */

void reverse(listint_t *temp, listint_t *last)
{
	listint_t *help = temp;

	while (help->next != last)
		help = help->next;
	temp->next = last;
	help->next = temp;
}

