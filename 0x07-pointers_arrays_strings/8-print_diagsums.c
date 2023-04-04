#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - a finc that prints the sum of 2 diagonals
 * @a: input
 * @size: input
 * Return: 0
 */
void print_diagsums(int *a, int size)
{
	int s1, s2, x;

	s1 = 0;
	s2 = 0;

	for (x = 0; x < size; x++)
	{
		s1 = s1 + a[x * size + x];
	}
	for (x = size - 1; x >= 0; x--)
	{
		s2 += a[x * size + (size - x - 1)];
	}
	printf("%d, %d\n", s1, s2);
}
