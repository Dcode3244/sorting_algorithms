#include "sort.h"
void forward(listint_t **list, listint_t **prv, listint_t **nxt, int *swap);
void backward(listint_t **list, listint_t **prv, listint_t **nxt, int *swap);

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Coctail sort algorithm
 * @list: the linked list to be sorted
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

		forward(list, &prev, &next, &swap);

		next = prev;
		prev = prev->prev;

		backward(list, &prev, &next, &swap);

		if (swap == 0)
			break;
		prev = next;
		next = next->next;
	}
}


/**
 * forward - places the large ints to theit correct position
 * while going forward through the doubly linked list
 * @list: the linked list to be sorted
 * @prv: pointer to the initital node of the linked list
 * @nxt: pointer to the second node of the linked list
 * @swap: holds value of 1 if swap is hapened, else 0
 */
void forward(listint_t **list, listint_t **prv, listint_t **nxt, int *swap)
{
	listint_t *prev = *prv;
	listint_t *next = *nxt;

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
			*swap = 1;
			print_list(*list);
		}
		else
		{
			prev = prev->next;
			next = next->next;
		}
	}
	*prv = prev;
	*nxt = next;
}


/**
 * backward - places the small ints to theit correct position
 * while going backward through the doubly linked list
 * @list: the linked list to be sorted
 * @prv: pointer to the second to last node of the linked list
 * @nxt: pointer to the last node of the linked list
 * @swap: holds value of 1 if swap is hapened, else 0
 */
void backward(listint_t **list, listint_t **prv, listint_t **nxt, int *swap)
{
	listint_t *prev = *prv;
	listint_t *next = *nxt;

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
				prev = next->prev;
			else
			{
				prev = prev->prev;
				next = next->next;
				*list = prev;
			}
			*swap = 1;
			print_list(*list);
		}
		else
		{
			prev = prev->prev;
			next = next->prev;
		}
	}
	*nxt = next;
	*prv = prev;
}
