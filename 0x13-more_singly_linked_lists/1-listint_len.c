#include "lists.h"

/**
 * listint_len - prints the num of elements
 * @h: traverse a lks-ls
 * Return: nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t a = 0;

	do {
		a++;
		h = h->next;
	} while (h);
	return (a);
}
