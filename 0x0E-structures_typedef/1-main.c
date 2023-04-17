#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    printf("My name is %s, and I am %.1f, and owner: %s :) - Woof!\n", my_dog.name, my_dog.age, my_dog.owner);
    return (0);
}
