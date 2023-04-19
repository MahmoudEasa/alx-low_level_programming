/**
 * int_index - searches for an integer
 * @array: array
 * @size: the number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: index of the first element
 *	or -1 if (no element matches or size <= 0)
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i, index = -1;

	if (size <= 0 || !array || !cmp)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]))
		{
			index = i;
			break;
		}

	return (index);
}

