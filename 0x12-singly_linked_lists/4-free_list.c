#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to first element in list
 */

void free_list(list_t *head)
{
	list_t *ptr;

	while (head)
	{
		if (head->str)
			free(head->str);
		ptr = head;
		head = head->next;
		free(ptr);
	}
}

