#include "sort.h"

/**
 * integer_swap - Swaps two integers in an array.
 * @a: Pointer to the first integer to be swapped.
 * @b: Pointer to the second integer to be swapped.
 */
void integer_swap(int *a, int *b)
{
	int iTemp;

	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

/**
 * h_partition - Orders a subset of an array of integers
 * according to the Hoare partition scheme.
 * @args: The array of integers.
 * @sz: The size of the array.
 * @leftside: The starting index of the subset to order.
 * @rightside: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int h_partition(int *args, size_t sz, int leftside, int rightside)
{
	int engine, iTop, iDown;

	engine = args[rightside];
	for (iTop = leftside - 1, iDown = rightside + 1; iTop < iDown;)
	{
		do {
			iTop++;
		} while (args[iTop] < engine);
		do {
			iDown--;
		} while (args[iDown] > engine);

		if (iTop < iDown)
		{
			integer_swap(args + iTop, args + iDown);
			print_array(args, sz);
		}
	}

		return (iTop);
}

/**
 * h_sort - Implements the quicksort algorithm through recursion.
 * @args: An array of integers to sort.
 * @sz: The size of the array.
 * @leftside: The starting index of the array partition to order.
 * @rightside: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme for efficient sorting.
 */
void h_sort(int *args, size_t sz, int leftside, int rightside)
{
	int engine;

	if (rightside - leftside > 0)
	{
		engine = h_partition(args, sz, leftside, rightside);
		h_sort(args, sz, leftside, engine - 1);
		h_sort(args, sz, engine, rightside);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 * order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements quicksort using the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	h_sort(array, size, 0, size - 1);
}
