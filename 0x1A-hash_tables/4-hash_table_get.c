#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: the value associated with the element
 *	or NULL if key couldn’t be found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *pos;

	if (!ht || !(ht->size) || !key || !(*key))
		return (NULL);

	index = hash_djb2((unsigned char *)key) % ht->size;

	pos = ht->array[index];

	while (pos)
	{
		if (strcmp(pos->key, key) == 0)
			return (pos->value);

		pos = pos->next;
	}

	return (NULL);
}

