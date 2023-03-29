/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements of the array
 */

void reverse_array(int *a, int n)
{
	int i, temp, half_n;

	if (n % 2 == 0)
		half_n = (n / 2);
	else
		half_n = (n - 1) / 2;

	for (i = 0; i < half_n; i++)
	{
		temp = a[i];
		a[i] = a[n - 1];
		a[n - 1] = temp;
		n--;
	}
}

