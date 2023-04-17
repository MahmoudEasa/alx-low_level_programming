#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: string
 * @age: float
 * @owner: string
 *
 * Return: new dog or NULL if function fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;
	int name_len = strlen(name);
	int owner_len = strlen(owner);

	new = (dog_t *)malloc(sizeof(dog_t));

	if (!new)
		return (NULL);

	new->name = malloc(sizeof(char) * (name_len + 1));
	if (!new->name)
	{
		free(new);
		return (NULL);
	}

	new->owner = malloc(sizeof(char) * (owner_len + 1));
	if (!new->owner)
	{
		free(new->name);
		free(new);
		return (NULL);
	}

	strcpy(new->name, name);
	new->age = age;
	strcpy(new->owner, owner);

	return (new);
}

