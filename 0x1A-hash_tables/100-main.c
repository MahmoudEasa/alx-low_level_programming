#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	shash_table_t *ht;
	int ret;
/*    shash_table_t *ht;
    char *get;

    ht = shash_table_create(1024);
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);
    shash_table_set(ht, "j", "1");
    shash_table_print(ht);
    shash_table_set(ht, "c", "2");
    shash_table_print(ht);
    shash_table_set(ht, "b", "3");
    shash_table_print(ht);
    shash_table_set(ht, "z", "4");
    shash_table_print(ht);
    shash_table_set(ht, "n", "5");
    shash_table_print(ht);
    shash_table_set(ht, "a", "6");
    shash_table_print(ht);
    shash_table_set(ht, "m", "7");
    shash_table_set(ht, "m", "3456");
    shash_table_print(ht);
    get = shash_table_get(ht, "m");
    printf("\nget m: %s\n", get);
    shash_table_print_rev(ht);
        shash_table_delete(ht);
    return (EXIT_SUCCESS);
*/


	ht = shash_table_create(30);
	ret = shash_table_set(ht, "USA", "Washington");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "France", "Paris");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "UK", "London");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Spain", "Madrid");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Germany", "Berlin");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "China", "Beijing");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Russia", "Moscow");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Bahrain", "Manama");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Canada", "Ottawa");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Brazil", "Brasilia");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Sweden", "Stockholm");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Iceland", "Reykjavik");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Japan", "Tokyo");
	printf("%d\n", ret);
	ret = shash_table_set(ht, "Australia", "Canberra");
	printf("%d\n", ret);
    	shash_table_print(ht);
    	shash_table_print_rev(ht);
	return (EXIT_SUCCESS);
}
