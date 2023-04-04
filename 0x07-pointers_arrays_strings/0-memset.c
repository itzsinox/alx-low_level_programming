#include "main.h"
/**
 * _memset - function that fills the first n bytes
 * @n: num of bites
 * @s: ptr
 * @b: cst byte
 * Return: new value of n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
