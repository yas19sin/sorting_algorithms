#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Represents the suits of a standard deck of cards.
 * @SPADE:   Spade suit.
 * @HEART:   Heart suit.
 * @CLUB:    Club suit.
 * @DIAMOND: Diamond suit.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

int compares_str(const char *s1, const char *s2);
char _value(deck_node_t *card);
void kind_sort_deck(deck_node_t **deck);
void value_sort_deck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
