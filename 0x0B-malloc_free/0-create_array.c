#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates arr of size and assign char
 * @size: size of arr
 * @c: char to assign
 * Description: creat arr of size and assign char c
 * Return: ptr to arr, NULL if fail
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	str = malloc(sizeof(char) * size);
	if (size == 0 || str == NULL);
	return (NULL);
	for (i = 0; i < size; i++)
		str[i] = c;
	return (str);
}
