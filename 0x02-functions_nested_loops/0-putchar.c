#include "_putchar.c"

/**
 * main - Entry point
 *
 * Return: Always (0) [Success]
 */

int main(void)
{
	char *putchar = "_putchar";
	int size = sizeof(putchar) / sizeof(putchar[1]);
	int i;

	for (i = 0; i < size; i++)
	{
		_putchar(putchar[i]);
	}
	_putchar('\n');
	return (0);
}

