#include "lists.h"

/**
 * add_nodeint_end - to add an node at the end
 * @head: ptr of the 1st elmt
 * @n: insert data
 * Return: ptr to node, ot NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *a;
	listint_t *tp = *head;

	a = malloc(sizeof(listint_t));
	if (!a)
		return (NULL);
	a->n = n;
	a->next = NULL;
	if (*head == NULL)
	{
		*head = a;
		return (a);
	}
	while (tp->next)
		tp = tp->next;
	tp->next = a;
	return (a);
}
