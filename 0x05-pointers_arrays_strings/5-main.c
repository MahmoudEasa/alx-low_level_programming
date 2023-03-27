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
	char s2[446] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

	printf("%s\n", s);
	rev_string(s);
	printf("%s\n", s);
	printf("%s\n", s1);
	rev_string(s1);
	printf("%s\n", s1);
	printf("%s\n", s2);
	rev_string(s2);
	printf("%s\n", s2);
	return (0);
}
