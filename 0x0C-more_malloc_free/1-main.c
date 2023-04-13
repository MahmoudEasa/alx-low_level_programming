#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *concat;

    concat = string_nconcat("Best ", "School !!!", 6);
    printf("1: %s\n", concat);
    free(concat);

    concat = string_nconcat("Best ", "", 6);
    printf("2: %s\n", concat);
    free(concat);

    concat = string_nconcat(NULL, "", 6);
    printf("3: %s\n", concat);
    free(concat);

    concat = string_nconcat(NULL, "School", 10);
    printf("4: %s\n", concat);
    free(concat);


    concat = string_nconcat("Best ", NULL, 6);
    printf("5: %s\n", concat);
    free(concat);

    concat = string_nconcat(NULL, NULL, 6);
    printf("6: %s\n", concat);
    free(concat);



    return (0);
}
