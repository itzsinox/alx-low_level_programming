#include "lists.h"
/**
 * sum_listint - the sum
 * @head: 1st node
 * Return: sum
 */
int sum_listint(listint_t *head)
{
	int s = 0;
	listint_t *tmp = head;

	while (tmp)
	{
		s += tmp->n;
		tmp = tmp->next;
	}
	return (s);
}
