#include <stdlib.h>
#include <stddef.h>
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

	new = (dog_t *)malloc(sizeof(dog_t));

	if (new == NULL)
		return (NULL);

	new->name = name;
	new->age = age;
	new->owner = owner;

	return (new);
}

