#include "main.h"
#include <stdio.h>
/**
 * is_prime_number - returns 1 if input int is a prime num
 * @n: input
 * @a: input
 * Return: 1 if input int is a prime number
 * and 0 otherwise
 */
int check_prime(int n, int a);
int is_prime_number(int n)
{
	return (check_prime(n, 2));
}
/**
 * check_prime - check if numbers
 * @n: input
 * @a: input
 * Return: input
 */
int check_prime(int n, int a)
{
	if (a >= n && n > 1)
		return (1);
	else if (n % a == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, a + 1));
}
