#include "main.h"
/**
 * flip_bits - to count num
 * @n: 1st num
 * @m: 2nd num
 * Return: num
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int x, c = 0;
	unsigned long int cur;
	unsigned long int exc = n ^ m;

	for (x = 63; x >= 0; x--)
	{
		cur = exc >> x;
		if (cur & 1)
			c++;
	}
	return (c);
}
