#include "main.h"
/**
 * factorial - returns the fact of given num
 * @n: input
 * Return: fact of given num
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
