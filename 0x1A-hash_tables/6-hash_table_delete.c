#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *pos, *temp;

	if (ht)
	{
		if (ht->array)
		{
			for (i = 0; i < ht->size; i++)
			{
				pos = ht->array[i];

				while (pos)
				{
					temp = pos->next;
					free(pos->key);
					free(pos->value);
					free(pos);
					pos = temp;
				}
			}

			free(ht->array);
		}
		free(ht);
	}
}

