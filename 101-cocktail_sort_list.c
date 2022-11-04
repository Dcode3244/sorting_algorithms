#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *prev, *next;
	int swap = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	prev = *list;
	next = (*list)->next;

	while (swap)	
	{
		swap = 0;
		while (next)
		{
			if (prev->n > next->n)
			{
				if (prev->prev)
					prev->prev->next = next;
				if (next->next)
					next->next->prev = prev;
				prev->next = next->next;
				next->prev = prev->prev;
				prev->prev = next;
				next->next = prev;

				if (prev->next)
					next = prev->next;
				else
				{
					prev = prev->prev;
					next = next->next;
				}
				swap = 1;
				print_list(*list);
			}
			else
			{
				prev = prev->next;
				next = next->next;
			}
		}
		next = prev;
		prev = prev->prev;

		while (prev)
		{
			if (prev->n > next->n)
			{
				if (next->next)
					next->next->prev = prev;
				if (prev->prev)
					prev->prev->next = next;
				prev->next = next->next;
				next->prev = prev->prev;
				prev->prev = next;
				next->next = prev;

				if (next->prev)
				{
					prev = next->prev;
				}
				else
				{
					prev = prev->prev;
					next = next->next;
					*list = prev;
				}
				swap = 1;
				print_list(*list);
			}
			else
			{
				prev = prev->prev;
				next = next->prev;
			}
		}
		if (swap == 0)
			break;
		prev = next;
		next = next->next;
	}
}
