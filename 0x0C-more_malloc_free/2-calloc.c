#include <stdlib.h>
#include "main.h"
/**
 * _memset - fils memory with a cst byte
 * @s: memory area to be filed
 * @b: char to copy
 * @n: num of times to copy b
 * Return: ptr to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
/**
 * _calloc - allocates memory for an arr
 * @nmemb: num of elements in the arr
 * @size: size of each element
 * Return: ptr to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
		return (NULL);
	_memset(ptr, 0, nmemb * size);
	return (ptr);
}
