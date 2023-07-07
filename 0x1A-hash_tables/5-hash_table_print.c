#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *pos;
	int found = 0;

	if (ht)
	{
		printf("{");
		for (i = 0; i < ht->size; i++)
		{
			pos = ht->array[i];
			while (pos)
			{
				if (found)
					printf(", ");

				found = 1;
				printf("'%s': '%s'", pos->key, pos->value);
				pos = pos->next;
			}
		}
		printf("}");
		printf("\n");
	}
}

