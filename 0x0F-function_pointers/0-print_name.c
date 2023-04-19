/**
 * print_name - prints a name
 * @name: string
 * @f: pointer to function
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}

