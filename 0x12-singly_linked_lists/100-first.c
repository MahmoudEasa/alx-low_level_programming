#include <stdio.h>

/**
 * print - print string before the main function is executed
 */

void __attribute__((constructor)) print()
{
	printf("You're beat! and yet, you must allow,\nI bore my house upon my back!\n");
}

