#include <stdio.h>
#include "main.h"
/**
 * _atoi - converts a str to int
 * @s: str to convert
 * Return: the in converted
 */
int _atoi(char *s)
{
	int i, j, k, l, f, d;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	f = 0;
	d = 0;
	while (s[l] != '\0')
		l++;
	while (i < l && f == 0)
	{
		if (s[i] == '-')
			++j;
		if (s[i] >= '0' && s[i] <= '9')
		{
			d = s[i] - '0';
			if (j % 2)
				d = -d;
			k = k * 10 + d;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}
	if (f == 0)
		return (0);
	return (k);
}
/**
 * main - prints two int
 * @argc: arg counter
 * @argv: arg vector
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int res, num1, num2;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
		num1 = _atoi(argv[1]);
		num2 = _atoi(argv[2]);
		res = num1 * num2;
		printf("%d\n", res);
	return (0);
}
