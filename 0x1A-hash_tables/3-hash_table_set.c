#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * hash_table_set - adds an element to the hash table
 * @ht: pointer to the hash table
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *pos;

	if (ht && ht->size && key && *key && value)
	{
		index = hash_djb2((unsigned char *)key) % ht->size;
		pos = ht->array[index];

		found_key(&pos, key, value);

		if (!pos)
			if (!allocate(ht, index, key, value))
				return (0);
	}
	else
		return (0);

	return (1);
}

/**
 * found_key - found key in hash table
 * @pos: position in hash table
 * @key: the key
 * @value: the value
 */

void found_key(hash_node_t **pos, const char *key, const char *value)
{
	while (*pos)
	{
		if (strcmp((*pos)->key, key) == 0)
		{
			strcpy((*pos)->value, value);
			break;
		}

		*pos = (*pos)->next;
	}
}

/**
 * allocate - allocate node
 * @ht: hash_table_t
 * @index: the index
 * @key: the key
 * @value: the value
 *
 * Return: 1 is success or 0
 */

int allocate(hash_table_t *ht, unsigned long int index,
		const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = (hash_node_t *) malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);

	new_node->key = (char *) malloc(sizeof(char) * strlen(key) + 1);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = (char *) malloc(sizeof(char) * (strlen(value) + 1));
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	strcpy(new_node->key, key);
	strcpy(new_node->value, value);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}


