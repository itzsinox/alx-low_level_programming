#include "main.h"
/**
 * _strlen_recursion - returns the length of a str
 * @s: input
 * Return: the length of str
 */
int _strlen_recursion(char *s)
{
	int longs = 0;

	if (*s)
	{
		longs++;
		longs += _strlen_recursion(s + 1);
	}
	return (longs);
}
