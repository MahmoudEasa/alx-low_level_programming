/**
 * swap_int - swap the values of two integers
 * @a: (int) Pointer to the first number
 * @b: (int) Pointer to the second number
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

