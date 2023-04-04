#include "main.h"
/**
 * _strspn - a function that gets thr lrngth of a prefic substring
 * @s: the initial segment
 * @accept: return val
 * Return : 0
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				n++;
				break;
			}
			else if (accept[i + 1] == '\0')
				return (n);
		}
		s++;
	}
	return (n);
}
