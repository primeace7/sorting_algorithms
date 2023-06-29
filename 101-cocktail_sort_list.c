#include "sort.h"

/**
 * cocktail_sort_list - sort a doubly-linked list with the
 *    cocktail shaker sort algorithm
 * @list: pointer to the head pointer of the list to sort
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *head;

	if (list == NULL || *list == NULL || *list->next == NULL)
		return;
	head = *list;

	while (head->next != NULL)
	{
		if (head->n > head->next->n)
		{
			head->next->prev = head->prev;
			if (head->prev != NULL)
				head->prev->next = head->next;
			head->prev = head->next;
			head->next = head->next->next;
			head->next->prev = head;
			head->prev->next = head;
		}
		else
			head = head->next;
	}

	while (head->prev != NULL)
	{
		if (head->n < head->prev->n)
		{
			head->prev->next = head->next;
			if (head->next != NULL)
				head->next->prev = head->prev;
			head->prev = head->prev->prev;
			head->next = head->prev->next;
			head->next->prev = head;
			head->prev->next = head;
		}
	}
}
