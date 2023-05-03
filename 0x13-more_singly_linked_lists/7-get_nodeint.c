#include "lists.h"

/**
 * get_nodeint_at_index - node at an index
 * @head: the 1st node
 * @index: index
 * Return: a pointer
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int b = 0;
	listint_t *tmp = head;

	while (tmp && b < index)
	{
		tmp = tmp->next;
		b++;
	}
	return (tmp ? tmp : NULL);
}
