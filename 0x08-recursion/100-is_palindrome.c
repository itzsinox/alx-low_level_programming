#include "main.h"

int last_index(char *s);
int check(char *s, int start, int end, int mod);

/**
 * last_index - cheks the last index
 * @s: string pointer
 * Return: int
 */
int last_index(char *s)
{
	int n = 0;

	if (*s > '\0')
		n += last_index(s + 1) + 1;
	return (n);
}
/**
 * is_palindrome - checks if a string is palindrome
 * @s: string to check
 * Return: 1 if true and 0 otherwise
 */
int is_palindrome(char *s)
{
	int end = last_index(s);

	return (check(s, 0, end - 1, end % 2));
}
/**
 * check - checks if the last and the first char are symetric
 * @s: string
 * @start: int moves from right to left
 * @end: int moves from left to right
 * @mod: int
 * Return: 1 if true and 0 otherwise
 */
int check(char *s, int start, int end, int mod)
{
	if ((start == end && mod != 0) || (start == end + 1 && mod == 0))
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (check(s, start + 1, end - 1, mod));
}
