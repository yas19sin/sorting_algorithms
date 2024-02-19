#include "sort.h"

/**
 * cocktail_sort_list - Sorts a list of integers in ascending order
 * using the Cocktail Shaker algorithm.
 * @list: Pointer to the head of a list of integers.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *iTemp, *algo;
	int algo_not_stirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iTemp = *list; iTemp->next != NULL;)
		iTemp = iTemp->next;

	while (algo_not_stirred == 0)
	{
		algo_not_stirred = 1;
		for (algo = *list; algo != iTemp; algo = algo->next)
		{
			if (algo->n > algo->next->n)
			{
				swap_ahead(list, &iTemp, &algo);
				print_list((const listint_t *)*list);
				algo_not_stirred = 0;
			}
		}
		for (algo = algo->prev; algo != *list;
				algo = algo->prev)
		{
			if (algo->n < algo->prev->n)
			{
				swap_behind(list, &iTemp, &algo);
				print_list((const listint_t *)*list);
				algo_not_stirred = 0;
			}
		}
	}
}

/**
 * swap_ahead - Swap a node in a listint_t
 * doubly-linked list with its next node.
 * @engine: Pointer to the head of a doubly-linked list.
 * @list: Pointer to the tail of the list.
 * @algo: Pointer to the current node in the Cocktail Shaker algorithm.
 */
void swap_ahead(listint_t **engine, listint_t **list, listint_t **algo)
{
	listint_t *iTemp = (*algo)->next;

	if ((*algo)->prev != NULL)
		(*algo)->prev->next = iTemp;
	else
		*engine = iTemp;
	iTemp->prev = (*algo)->prev;
	(*algo)->next = iTemp->next;
	if (iTemp->next != NULL)
		iTemp->next->prev = *algo;
	else
		*list = *algo;
	(*algo)->prev = iTemp;
	iTemp->next = *algo;
	*algo = iTemp;
}

/**
 * swap_behind - Swap a node in a listint_t doubly-linked
 * list of integers with the node behind it.
 * @engine: A pointer to the head of a doubly-linked list of integers.
 * @list: A pointer to the tail of the doubly-linked list.
 * @algo: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_behind(listint_t **engine, listint_t **list, listint_t **algo)
{
	listint_t *iTemp = (*algo)->prev;

	if ((*algo)->next != NULL)
		(*algo)->next->prev = iTemp;
	else
		*list = iTemp;
	iTemp->next = (*algo)->next;
	(*algo)->prev = iTemp->prev;
	if (iTemp->prev != NULL)
		iTemp->prev->next = *algo;
	else
		*engine = *algo;
	(*algo)->next = iTemp;
	iTemp->prev = *algo;
	*algo = iTemp;
}
