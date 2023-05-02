#include "lists.h"

/**
 * add_nodeint - to add new node
 * @head: ptr to 1st node
 * @n: to insert data int the new node
 * Return: ptr, or NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *a;

	a = malloc(sizeof(listint_t));
	if (!a)
		return (NULL);
	a->n = n;
	a->next = *head;
	*head = a;
	return (a);
}
