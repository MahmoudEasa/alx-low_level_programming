#include <stdio.h>

int _sqrt_helper(int n, int start, int end);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: Number
 *
 * Return: square root of n
 */

int _sqrt_recursion(int n)
{
	int root;

	if (n < 0)
		return (-1);

	if (n <= 1)
		return (n);

	root = _sqrt_helper(n, 1, n);
	return (root);
}

/**
 * _sqrt_helper - help me to find the square root
 * @n: Number
 * @start: Number
 * @end: Number
 *
 * Return: Square root of n
 */

int _sqrt_helper(int n, int start, int end)
{
	int mid = ((start + end) / 2);

	if (start > end)
		return (-1);

	if ((mid * mid) == n)
		return (mid);

	if (mid > 10000)
		return (_sqrt_helper(n, start, mid - 1));

	if ((mid * mid) < n)
		return (_sqrt_helper(n, mid + 1, end));
	else
		return (_sqrt_helper(n, start, mid - 1));
}

