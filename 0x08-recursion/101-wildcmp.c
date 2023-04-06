#include "main.h"
char *move_past_start(char *s2);
int inception(char *s1, char *s2);

/**
 * move_past_start - iterates past astorisk
 * @s2: the second string, can hold wildcard
 * Return: the pointer past start
 */
char *move_past_start(char *s2)
{
	if (*s2 == '*')
		return (move_past_start(s2 + 1));
	else
		return (s2);
}

/**
 * inception - makes reality
 * @s1: first string
 * @s2: second string
 * Return: 1 if identical and 0 otherwise
 */
int inception(char *s1, char *s2)
{
	int ret = 0;

	if (*s1 == 0)
		return (0);
	else if (*s1 == *s2)
		ret += wildcmp(s1 + 1, s2 + 1);
	ret += inception(s1 + 1, s2);
	return (ret);
}

/**
 * wildcmp - compares two strings if they are identical
 * @s1: first string
 * @s2: second string
 * Return: 1 if true and 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	int ret = 0;

	if (!*s1 && *s2 == '*' && !*move_past_start(s2))
		return (1);
	else if (*s1 == *s2)
	{
		if (!*s1)
			return (1);
		return (wildcmp(s1 + 1, *s2 == '*' ? s2 : s2 + 1));
	}
	else if (!*s1 || !s2)
		return (0);
	else if (*s2 == '*')
	{
		s2 = move_past_start(s2);
		if (!*s2)
			return (1);
		else if (*s1 == *s2)
			ret += wildcmp(s1 + 1, s2 + 1);
		ret += inception(s1, s2);
		return (!!ret);
	}
	return (0);
}
