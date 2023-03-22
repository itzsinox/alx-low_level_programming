#include "main.h"
/**
 * print_sign - a program that prints the sign of a number
 * @n: a parameter that should be printed
 * Return: 1 if positive +
 * and 0 if zero 0
 * and -1 otherwise
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}
