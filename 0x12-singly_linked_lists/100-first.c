#include <stdio.h>

/**
 * print - print string before the main function is executed
 */

void __attribute__((constructor)) print()
{
	char *str1 = "I bore my house upon my back!\n";
	char *str2 = "You're beat! and yet, you must allow,\n";

	printf("%s%s", str1, str2);
}

