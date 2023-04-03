#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello";
    char *s1 = "";
    char *s2 = "h";
    char *f;

    f = _strchr(s, 'l');

    if (f != NULL)
    {
        printf("%s\n", f);
    }

    f = _strchr(s1, 'e');

    if (f != NULL)
    {
        printf("%s\n", f);
    }

    f = _strchr(s2, 'o');

    if (f != NULL)
    {
        printf("%s\n", f);
    }

    f = _strchr(s2, 'h');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
 

   return (0);
}
