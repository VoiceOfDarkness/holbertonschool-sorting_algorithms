#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (!list || !*list || !(*list)->next)
		return;

	curr = (*list)->next;
	while (curr)
	{
		tmp = curr->next;
		while (curr->prev && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;
			if (curr->next)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;
			if (!curr->prev)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
		}
		curr = tmp;
	}
