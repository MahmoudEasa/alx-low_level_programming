#include "hash_tables.h"
#include <stdlib.h>


/**
 * hash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table
 *	or NULL If something went wrong
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new;
	unsigned long int i;

	new = (hash_table_t *) malloc(sizeof(hash_table_t));
	if (!new)
		return (NULL);

	new->array = (hash_node_t **) calloc(size, sizeof(hash_node_t *));
	if (!(new->array))
	{
		free(new);
		return (NULL);
	}

	new->size = size;

	for (i = 0; i < size; i++)
		new->array[i] = NULL;

	return (new);
}

