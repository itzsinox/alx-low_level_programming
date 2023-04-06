#include "main.h"
/**
 * is_palindrome - checks if a string is palindrome
 * @s: string to check
 * Return: 1 if true and 0 otherwise
 */
/**
 * last_index - returns the last char of a string
 * @s: string pointer
 * Return: int
 */
int last_index(char *s);

/**
 * check - checks for the palindrome
 * @s: string
 * @start: int moves from right to left
 * @end: int moves from left to right
 * @mod: int
 * Return: 1 if parlindrome true and 0 otherwise
 */
int check(char *s, int start, int end, int mod);

int last_index(char *s)
{
	int n = 0;

	if (*s > '\0')
		n += last_index(s + 1) + 1;
	return (n);
}

int is_palindrome(char *s)
{
	int end = last_index(s);

	return (check(s, 0, end - 1, end % 2));
}

int check(char *s, int start, int end, int mod)
{
	if ((start == end && mod != 0) || (start == end + 1 && mod == 0))
		return (1);
	else if (s[start] != s[end])
		return (0);
	else
		return (check(s, start + 1, end - 1, mod));
}
