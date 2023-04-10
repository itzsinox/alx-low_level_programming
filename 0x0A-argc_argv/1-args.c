#include <stdio.h>
#include "main.h"
/**
 * main - prints the num of arg
 * @argc: arg counter
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);
	return (0);
}
