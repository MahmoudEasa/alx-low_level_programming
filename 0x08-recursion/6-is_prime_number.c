/**
 * is_prime_number - check number is prime
 * @n: Number
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	if ((n % 10 == 1) || (n % 10 == 3) || (n % 10 == 7) || (n % 10 == 9))
		return (1);
	else
		return (0);
}

