#include "sort.h"

/**
 * insertion_sort_list - sort a doubly-linked list with insertion sort
 * @list: pointer to the list's head node pointer
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *head;

	if (list == NULL)
		return;

	head = *list;
	iter = NULL;

	if (head == NULL || head->next == NULL)
		return;

	for (head = head->next; head != NULL; head = iter)
	{
		iter = head->next;

		while(head->prev != NULL && head->n < head->prev->n)
		{
			if (head->next != NULL)
				head->next->prev = head->prev;
			head->prev->next = head->next;
			head->next = head->prev;
			if (head->prev->prev != NULL)
				head->prev->prev->next = head;
			head->prev = head->prev->prev;
			head->next->prev = head;
			if (head->prev == NULL)
				*list = head;
			print_list(*list);
		}
	}
}
