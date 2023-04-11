#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s, *s2, *s3, *s4;

    s = str_concat("Betty ", "Holberton");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);

    s2 = str_concat("Hello", NULL);
    if (s2 == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s2);

    s3 = str_concat(NULL, "Hello");
    if (s3 == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s3);

    s4 = str_concat(NULL, NULL);
    if (s4 == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s4);
 
    free(s);
    free(s2);
    free(s3);
    free(s4);

    return (0);
}
