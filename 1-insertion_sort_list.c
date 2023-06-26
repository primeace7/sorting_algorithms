#include "sort.h"

/**
 * insertion_sort_list - sort a doubly-linked list with insertion sort
 * @list: pointer to the list's head node pointer
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *head, *hold;

	head = *list;
	iter = head;
	hold = NULL;

	while (head != NULL && head->next != NULL)
	{
		hold = head->next;
		if (iter->n > hold->n)
		{
			head->next = hold->next;
			if (head->next != NULL)
				head->next->prev = head;
			while(iter != NULL && iter->n > hold->n)
				iter = iter->prev;
		}

		if (iter == NULL)
		{
			hold->prev = NULL;
			hold->next = *list;
			*list = hold;
		}

		else if (iter != head)
		{
			hold->next = iter->next;
			hold->prev = iter;
			iter->next = hold;
		}

		if (iter == head)
			head = head->next;
		iter = head;
		print_list(*list);
	}
}
