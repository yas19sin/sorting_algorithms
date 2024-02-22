#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define gotParent(i) (((i) - 1) / 2)
#define gotLeft(i) (2 * (i) + 1)
#define gotRight(i) (2 * (i) + 2)

#define UP 0
#define DOWN 1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Project functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void recursive_quick_sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_behind(listint_t **engine, listint_t **list, listint_t **algo);
void swap_ahead(listint_t **engine, listint_t **list, listint_t **algo);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
int max_array(int *array, int size);
void sort_radix(int *args, size_t size, int digit, int *buffer);
void radix_sort(int *array, size_t size);
void integer_swap(int *a, int *b);
void bit_merge(int *arg, size_t sz, size_t begin, size_t szbit, char asc);
void bit_seq(int *arg, size_t sz, size_t begin, size_t szbit, char asc);
void bitonic_sort(int *array, size_t size);
void integer_swap(int *a, int *b);
int h_partition(int *args, size_t sz, int leftside, int rightside);
void h_sort(int *args, size_t sz, int leftside, int rightside);
void quick_sort_hoare(int *array, size_t size);

#endif /* ENDIF */
