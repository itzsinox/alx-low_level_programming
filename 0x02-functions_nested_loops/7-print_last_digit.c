#include "main.h"
/**
 * print_last_digit - a program that prints the las digit of a number
 * @i: parameter to be printed
 * Return: j
 */
int print_last_digit(int i)
{
	int j;

	j = i % 10;
	if (i < 0)
		j = -j;
	return (j);
}
