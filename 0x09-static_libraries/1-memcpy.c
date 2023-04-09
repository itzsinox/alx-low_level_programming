#include "main.h"
/**
 * _memcpy - function that copies n bytes
 * @n: num of bytes
 * @dest: memory area
 * @src: memory area
 * Return: copied memory with n bytes changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i = 0;
	int a = n;

	for (; i < a; i++)
	{
		dest[i] = src[i];
		n--;
	}
	return (dest);
}
