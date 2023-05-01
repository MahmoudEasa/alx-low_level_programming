#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to first element
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ptr = head, *next = head->next;
	size_t count = 0;

	if (!head)
		exit(98);

	while ((ptr && next && (next < ptr)))
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		ptr = ptr->next;
		next = next->next;
		count++;
	}
	printf("[%p] %d\n", (void *)ptr, ptr->n);
	count++;

	if (next)
	{
		printf("-> [%p] %d\n", (void *)next, next->n);
		exit(98);
	}

	return (count);
}

