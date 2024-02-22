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
 * bit_merge - Sorts a bitonic sequence inside an array of integers.
 * @arg: An array of integers.
 * @sz: The size of the array.
 * @begin: The starting index of the bitonic sequence in the array to sort.
 * @szbit: The size of the bitonic sequence to sort.
 * @asc: The direction to sort in (ascending or descending).
 */
void bit_merge(int *arg, size_t sz, size_t begin, size_t szbit, char asc)
{
	size_t i, iJump = szbit / 2;

	if (szbit > 1)
	{
		for (i = begin; i < begin + iJump; i++)
		{
			if ((asc == UP && arg[i] > arg[i + iJump]) ||
				(asc == DOWN && arg[i] < arg[i + iJump]))
				integer_swap(arg + i, arg + i + iJump);
				}

		bit_merge(arg, sz, begin, iJump, asc);
		bit_merge(arg, sz, begin + iJump, iJump, asc);
	}
}

/**
 * bit_seq - Converts an array of integers into a bitonic sequence.
 * @arg: An array of integers.
 * @sz: The size of the array.
 * @begin: The starting index of a block in the building bitonic sequence.
 * @szbit: The size of a block in the building bitonic sequence.
 * @asc: The direction to sort the bitonic sequence block.
 */
void bit_seq(int *arg, size_t sz, size_t begin, size_t szbit, char asc)
{
	size_t iCut = szbit / 2;
	char *string = (asc == UP) ? "UP" : "DOWN";

	if (szbit > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", szbit, sz, string);
		print_array(arg + begin, szbit);

		bit_seq(arg, sz, begin, iCut, UP);
		bit_seq(arg, sz, begin + iCut, iCut, DOWN);
		bit_merge(arg, sz, begin, szbit, asc);

		printf("Result [%lu/%lu] (%s):\n", szbit, sz, string);
		print_array(arg + begin, szbit);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. The function is
 * designed for arrays of size 2^k where k >= 0 (i.e., size is a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bit_seq(array, size, 0, size, UP);
}
