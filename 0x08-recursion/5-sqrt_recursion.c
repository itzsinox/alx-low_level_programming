#include "main.h"
/**
 * _sqrt_recursion - returns the natural sqrt of a num
 * @n: input
 * @val: input
 * Return: the natural sqrt of num
 */
int square(int n, int val);
int _sqrt_recursion(int n)
{
	return (square(n, 1));
}
/**
 * square - return the square of num
 * @n: input
 * @val: input
 * Return: square of num
 */
int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);
}
