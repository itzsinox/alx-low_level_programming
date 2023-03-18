#include <stdio.h>
/**
 * main - a prog that prints tebahpla
 * Return: always 0
 */
int main(void)
{
	char alp;

	for (alp = 'z'; alp >= 'a'; alp--)
	{
		putchar(alp);
	}
	putchar('\n');
	return (0);
}
