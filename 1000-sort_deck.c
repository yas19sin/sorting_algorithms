#include "deck.h"

/**
 * compares_str - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive value if s1 > s2,
 *         0 if s1 is equal to s2,
 *         Negative value if s1 < s2.
 */

int compares_str(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * _value - Retrieves the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char _value(deck_node_t *card)
{
	if (compares_str(card->card->value, "Ace") == 0)
		return (0);
	if (compares_str(card->card->value, "1") == 0)
		return (1);
	if (compares_str(card->card->value, "2") == 0)
		return (2);
	if (compares_str(card->card->value, "3") == 0)
		return (3);
	if (compares_str(card->card->value, "4") == 0)
		return (4);
	if (compares_str(card->card->value, "5") == 0)
		return (5);
	if (compares_str(card->card->value, "6") == 0)
		return (6);
	if (compares_str(card->card->value, "7") == 0)
		return (7);
		if (compares_str(card->card->value, "8") == 0)
		return (8);
	if (compares_str(card->card->value, "9") == 0)
		return (9);
	if (compares_str(card->card->value, "10") == 0)
		return (10);
	if (compares_str(card->card->value, "Jack") == 0)
		return (11);
	if (compares_str(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * kind_sort_deck - Sorts a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void kind_sort_deck(deck_node_t **deck)
{
	deck_node_t *iTers, *iSort, *iTemp;

	for (iTers = (*deck)->next; iTers != NULL; iTers = iTemp)
	{
		iTemp = iTers->next;
		iSort = iTers->prev;
		while (iSort != NULL && iSort->card->kind > iTers->card->kind)
		{
			iSort->next = iTers->next;
			if (iTers->next != NULL)
				iTers->next->prev = iSort;
			iTers->prev = iSort->prev;
			iTers->next = iSort;
			if (iSort->prev != NULL)
				iSort->prev->next = iTers;
			else
				*deck = iTers;
			iSort->prev = iTers;
			iSort = iTers->prev;
		}
	}
}

/**
 * value_sort_deck - Sorts a deck of cards from spades to diamonds
 * and from ace to king within each suit.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void value_sort_deck(deck_node_t **deck)
{
	deck_node_t *iTers, *iSort, *iTemp;

	for (iTers = (*deck)->next; iTers != NULL; iTers = iTemp)
	{
		iTemp = iTers->next;
		iSort = iTers->prev;
		while (iSort != NULL &&
				  iSort->card->kind == iTers->card->kind &&
				  _value(iSort) > _value(iTers))
		{
			iSort->next = iTers->next;
			if (iTers->next != NULL)
				iTers->next->prev = iSort;
			iTers->prev = iSort->prev;
			iTers->next = iSort;
			if (iSort->prev != NULL)
				iSort->prev->next = iTers;
			else
				*deck = iTers;
			iSort->prev = iTers;
			iSort = iTers->prev;
		}
	}
}

/**
 * sort_deck - Sorts a deck of cards from ace to king and
 * from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	kind_sort_deck(deck);
	value_sort_deck(deck);
}
