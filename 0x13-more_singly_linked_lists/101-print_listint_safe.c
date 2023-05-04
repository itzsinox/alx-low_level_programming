#include <stdio.h>
#include "lists.h"

size_t print_listint_safe(const listint_t *head);
size_t looped_listint_len(const listint_t *head);

/**
 * print_listint_safe - safely print lists
 * @head: head's ptr
 * Return: nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nd, index = 0;

	nd = looped_listint_len(head);
	if (nd == 0)
	{
		for (; head != NULL; nd++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (index = 0; index < nd; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (nd);
}

/**
 * looped_listint_len - counts number
 * @head: head's ptr
 * Return: numbers of nodes or 0
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tor, *r;
	size_t nd = 1;

	if (head == NULL || head->next == NULL)
		return (0);
	tor = head->next;
	r = (head->next)->next;
	while (r)
	{
		if (tor == r)
		{
			tor = head;
			while (tor != r)
			{
				nd++;
				tor = tor->next;
				r = r->next;
			}
			tor = tor->next;
			while (tor != r)
			{
				nd++;
				tor = tor->next;
			}
			return (nd);
		}
		tor = tor->next;
		r = (r->next)->next;
	}
	return (0);
}
