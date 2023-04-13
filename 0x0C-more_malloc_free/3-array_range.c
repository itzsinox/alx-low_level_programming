#include <stdlib.h>
#include "main.h"
/**
 * array_range - creates an arr of int
 * @min: min range of val stored
 * @max: max range of val stored and num of elements
 * Return: ptr to the new arr
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	ptr = malloc(sizeof(int) * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; min <= max; i++)
		ptr[i] = min++;
	return (ptr);
}
