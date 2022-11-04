#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *next, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	prev = *list;
	next = (*list)->next;
	temp = NULL;
	while (next)
	{
		if (prev->n <= next->n)
		{
			prev = prev->next;
			next = next->next;
			continue;
		}
		if (prev->prev != NULL)
			prev->prev->next = next;
		if (next->next != NULL)
			next->next->prev = prev;
		prev->next = next->next;
		next->prev = prev->prev;
		prev->prev = next;
		next->next = prev;

		if (next->prev != NULL)
			prev = next->prev;
		else
		{
			temp = prev;
			prev = next;
			next = temp;
			*list = prev;
		}
		print_list(*list);
	}
}
