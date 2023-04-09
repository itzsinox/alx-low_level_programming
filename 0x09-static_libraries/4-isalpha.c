#include "main.h"
/**
 * _isalpha - a program that checks for alphabetic character
 * @c: parameter to be printed
 * Return: 1 if true
 * and 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) ||  (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
