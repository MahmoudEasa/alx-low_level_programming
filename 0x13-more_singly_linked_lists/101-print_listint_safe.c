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
	const listint_t *ptr = head;
	const listint_t *arr[1024];
	size_t count = 0, i;

	if (!head)
	{
		printf("0\n");
		exit(98);
	}

	while (ptr)
	{
		for (i = 0; i < count; i++)
			if (arr[i] == ptr)
			{
				printf("-> [%p] %d\n", (void *)ptr, ptr->n);
				return (count);
			}

		arr[count] = ptr;
		count++;

		printf("[%p] %d\n", (void *)ptr, ptr->n);
		ptr = ptr->next;
	}

	return (count);
}

