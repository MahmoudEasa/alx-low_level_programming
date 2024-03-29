#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table
 *	or NULL If something went wrong
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new;
	unsigned long int i;

	if (size <= 0)
		return (NULL);

	new = (shash_table_t *) malloc(sizeof(shash_table_t));
	if (!new)
		return (NULL);

	new->array = (shash_node_t **) calloc(size, sizeof(shash_node_t *));
	if (!(new->array))
	{
		free(new);
		return (NULL);
	}

	new->size = size;
	new->shead = NULL;
	new->stail = NULL;

	for (i = 0; i < size; i++)
		new->array[i] = NULL;

	return (new);
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: pointer to the hash table
 * @key: the key
 * @value: the value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *pos;

	if (ht && ht->size && key && *key && value)
	{
		index = hash_djb2((unsigned char *)key) % ht->size;
		pos = ht->array[index];

		if (!sfound_key(&pos, key, value))
			return (0);

		if (!pos)
			if (!sallocate(ht, index, key, value))
				return (0);
	}
	else
		return (0);

	return (1);
}

/**
 * sfound_key - found key in hash table
 * @pos: position in hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if success or 0
 */

int sfound_key(shash_node_t **pos, const char *key, const char *value)
{
	size_t c_val_len, val_len;

	while (*pos)
	{
		if (strcmp((*pos)->key, key) == 0)
		{
			c_val_len = strlen((*pos)->value);
			val_len = strlen(value);
			if (c_val_len < val_len)
			{
				(*pos)->value = (char *)
					realloc((*pos)->value, val_len + 1);
				if (!((*pos)->value))
					return (0);
			}

			strcpy((*pos)->value, value);
			break;
		}

		*pos = (*pos)->next;
	}
	return (1);
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

int sallocate(shash_table_t *ht, unsigned long int index,
		const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = (shash_node_t *) malloc(sizeof(shash_node_t));
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
	new_node->snext = NULL;
	new_node->sprev = NULL;
	new_node->next = NULL;

	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	check_hash_head_tail(ht, new_node, key);
	return (1);
}

/**
 * check_hash_head_tail - check if the node is less than the head
 *	or greater than the tail
 * @ht: the hash table
 * @pos: the position
 * @key: the key
 */

void check_hash_head_tail(shash_table_t *ht,
		shash_node_t *pos, const char *key)
{
	int hash_head, hash_tail;

	if (!(ht->shead))
		ht->shead = pos;
	if (!(ht->stail))
		ht->stail = pos;
	if (ht->shead && ht->stail)
	{
		hash_head = strcmp(ht->shead->key, key);
		hash_tail = strcmp(key, ht->stail->key);

		if (hash_head > 0)
		{
			ht->shead->sprev = pos;
			pos->snext = ht->shead;
			ht->shead = pos;
		}
		else if (hash_tail > 0)
		{
			ht->stail->snext = pos;
			pos->sprev = ht->stail;
			ht->stail = pos;
		}
		else
			add_node(ht, pos);
	}
}

/**
 * add_node - add node inside list
 * @ht: the hash table
 * @pos: new node
 */

void add_node(shash_table_t *ht, shash_node_t *pos)
{
	shash_node_t *temp;
	int pos_key;

	temp = ht->shead;
	while (temp)
	{
		pos_key = strcmp(temp->key, pos->key);
		if (pos_key > 0)
		{
			insert(temp, pos);
			break;
		}
		temp = temp->snext;
	}
}

/**
 * insert - add node in prev
 * @pos: the position
 * @new_node: the new node
 */

void insert(shash_node_t *pos, shash_node_t *new_node)
{
	new_node->snext = pos;
	if (pos->sprev)
		pos->sprev->snext = new_node;

	new_node->sprev = pos->sprev;
	pos->sprev = new_node;
}

/**
 * push - add node in next
 * @pos: the position
 * @new_node: the new node
 */

void push(shash_node_t *pos, shash_node_t *new_node)
{
	new_node->sprev = pos;
	if (pos->snext)
		pos->snext->sprev = new_node;

	new_node->snext = pos->snext;
	pos->snext = new_node;
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: the value associated with the element
 *	or NULL if key couldn’t be found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *pos;

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

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *pos;

	if (ht)
	{
		pos = ht->shead;

		printf("{");
		while (pos)
		{
			printf("'%s': '%s'", pos->key, pos->value);
			if (pos->snext)
				printf(", ");
			pos = pos->snext;
		}
		printf("}\n");
	}
}

/**
 * shash_table_print_rev - print the hash tables key/value
 *	pairs in reverse order using the sorted linked list
 * @ht: the hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *pos;

	if (ht)
	{
		pos = ht->stail;

		printf("{");
		while (pos)
		{
			printf("'%s': '%s'", pos->key, pos->value);
			if (pos->sprev)
				printf(", ");
			pos = pos->sprev;
		}
		printf("}\n");
	}
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *pos, *temp;

	if (ht)
	{
		if (ht->array)
		{
			pos = ht->shead;

			while (pos)
			{
				temp = pos->snext;
				free(pos->key);
				free(pos->value);
				free(pos);
				pos = temp;
			}

			free(ht->array);
		}
		free(ht);
	}
}

