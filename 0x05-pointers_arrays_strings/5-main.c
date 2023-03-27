#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[10] = "My School";
	char s1[11]= "Holberton!";

	printf("%s\n", s);
	rev_string(s);
	printf("%s\n", s);
	printf("%s\n", s1);
	rev_string(s1);
	printf("%s\n", s1);
	return (0);
}
