#include "main.h"
/**
 * _strchr - func that locates a char in a string
 * @c: char
 * @s: string
 * Return: 0
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&S[i]);
	}
	return (0);
}
