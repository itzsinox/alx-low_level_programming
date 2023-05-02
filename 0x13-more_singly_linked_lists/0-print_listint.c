#include "lists.h"

/**
 * print_listint - prt elmt
 * @h: print lkd-ls
 * Return: nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t a = 0;

	while (a)
	{
		printf("%d\n", h->n);
		a++;
		h = h->next;
	}
	return (a);
}
