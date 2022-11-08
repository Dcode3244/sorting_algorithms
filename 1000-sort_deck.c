#include "deck.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insertion_sort_deck(deck_node_t **deck);
void insertion_sort_suit(deck_node_t **deck);
void set_a_b(deck_node_t *next, deck_node_t *prev, int *a, int *b);
void swap(deck_node_t **deck, deck_node_t **prev, deck_node_t **next,
		deck_node_t **temp);
/**
 * sort_deck -sorts a deck of cards
 * @deck: the deck of cards to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;

	insertion_sort_deck(deck);
	insertion_sort_suit(deck);
}

/**
 * insertion_sort_deck - sorts a doubly linked list of decks
 * from Ace to King
 * insertion sort algorithm
 * @deck: pointer to the head of the deck of cards linked list
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int a, b;
	deck_node_t *next, *prev, *temp;

	prev = *deck;
	next = (*deck)->next;
	temp = NULL;
	while (next)
	{
		set_a_b(next, prev, &a, &b);
		if (a <= b)
		{
			prev = prev->next;
			next = next->next;
			continue;
		}
		swap(deck, &prev, &next, &temp);
	}
}


/**
 * insertion_sort_suit - sorts a doubly linked list of decks
 * in form Spades to Diamonds
 * insertion sort algorithm
 * @deck: pointer to the head of the deck of cards linked list
 */
void insertion_sort_suit(deck_node_t **deck)
{
	deck_node_t *next, *prev, *temp;

	prev = *deck;
	next = (*deck)->next;
	temp = NULL;
	while (next)
	{
		if (prev->card->kind <= next->card->kind)
		{
			prev = prev->next;
			next = next->next;
			continue;
		}
		swap(deck, &prev, &next, &temp);
	}
}

/**
 * set_a_b - converts cards value to int
 * @next: pointer to the next node to be compared
 * @prev: pointer to the node to be compared
 * @a: prev card value
 * @b: next card value
 */
void set_a_b(deck_node_t *next, deck_node_t *prev, int *a, int *b)
{
	if (*(prev->card->value) == 'A')
		*a = 1;
	else if (*(prev->card->value) == 'J')
		*a = 11;
	else if (*(prev->card->value) == 'Q')
		*a = 12;
	else if (*(prev->card->value) == 'K')
		*a = 13;
	else
		*a = atoi(prev->card->value);

	if (*(next->card->value) == 'A')
		*b = 1;
	else if (*(next->card->value) == 'J')
		*b = 11;
	else if (*(next->card->value) == 'Q')
		*b = 12;
	else if (*(next->card->value) == 'K')
		*b = 13;
	else
		*b = atoi(next->card->value);
}

/**
 * swap - swaps unordered cards
 * @deck: the deck of cards
 * @prv: the first value to be swaped
 * @nxt: the next value to be swaped
 * @tmp: temporary pointer
 */
void swap(deck_node_t **deck, deck_node_t **prv, deck_node_t **nxt,
		deck_node_t **tmp)
{
	deck_node_t *prev = *prv;
	deck_node_t *next = *nxt;
	deck_node_t *temp = *tmp;

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
		*deck = prev;
	}
	*prv = prev;
	*tmp = temp;
	*nxt = next;
}
