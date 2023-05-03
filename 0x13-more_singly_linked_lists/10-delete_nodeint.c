#include "lists.h"

/**
 * delete_nodeint_at_index - to delete node
 * @head: ptr
 * @index: index
 * Return: 1 or -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head;
	listint_t *cur = NULL;
	unsigned int b = 0;

	if (index == 0)
	{
		*head = (*head)->next;
		free(tmp);
		return (1);
	}
	while (b < index - 1)
	{
		if (!tmp || !(tmp->next))
			return (-1);
		tmp = tmp->next;
		b++;
	}
	cur = tmp->next;
	tmp->next = cur->next;
	free(cur);
	return (1);
}
