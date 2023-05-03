#include "lists.h"

/**
 * pop_listint - to delete a head's node
 * @head: ptr to 1st elm
 * Return: the deleted data
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int a;

	if (!head || !*head)
		return (0);
	a = (*head)->n;
	tmp = (*head)->next;
	free(*head);
	*head = tmp;
	return (a);
}
