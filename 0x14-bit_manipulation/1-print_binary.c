#include "main.h"

/**
 * print_binary - dec to bin
 * @n: num
 */
void print_binary(unsigned long int n)
{
	int x, c = 0;
	unsigned long int cur;

	for (x = 63; x >= 0; x--)
	{
		cur = n >> x;
		if (cur & 1)
		{
			_putchar('1');
			c++;
		}
		else if (c)
			_putchar('0');
	}
	if (!c)
		_putchar('0');
}
