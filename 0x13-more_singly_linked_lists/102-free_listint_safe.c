#include "lists.h"

/**
 * free_listint_safe - free
 * @h: ptr
 * Return: num
 */
size_t free_listint_safe(listint_t **h)
{
	size_t l = 0;
	int df;
	listint_t *tmp;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		df = *h - (*h)->next;
		if (df > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			l++;
		}
		else
		{
			free(*h);
			*h = NULL;
			l++;
			break;
		}
	}
	*h = NULL;
	return (l);
}
