#include "sort.h"

/**
 * shift_print_node - print the current state of a doubly-linked list
 * each time a node is shifted in an insertion sort
 * @iterator: the iterating pointer used to search for the correct position
 * of the node in the list
 * @temp: the node to be moved to the correct position
 */

void shift_print_node(listint_t *iterator, listint_t *temp, listint_t *list)
{
	temp->next->prev = iterator->next;
	iterator->next->next = temp->next;
	temp->next = iterator->next;
	iterator->next = temp;
	temp->prev = iterator;

	print_list(list);

	iterator->next = temp->next;
	iterator->next->prev = iterator;
}

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
			while (iter != NULL && iter->n > hold->n)
			{
				iter = iter->prev;
				shift_print_node(iter, hold, *list);
			}
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
