#include "lists.h"

/**
 * reverse_listint - reverse llists
 * @head: ptr
 * Return: ptr of 1st node
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *p = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = p;
		p = *head;
		*head = next;
	}
	*head = p;
	return (*head);
}
