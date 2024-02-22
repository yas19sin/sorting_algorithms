#include "sort.h"

/**
 * find_array_max - Finds the maximum element in an array.
 *
 * @array: The array containing elements.
 * @size: The size of the array.
 *
 * Return: The maximum element in the array.
 *
 * Description: This function takes an array and its size as input,
 * then returns the maximum element present in the array.
 */
int find_array_max(int *array, size_t size)
{
	int iMax;
	size_t iSize;

	iMax = array[0];
	for (iSize = 1; iSize < size; iSize++)
	{
		if (array[iSize] > iMax)
		{
			iMax = array[iSize];
		}
	}
	return (iMax);
}

/**
 * counting_sort - Sorts an array in ascending order using
 * the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function implements the Counting Sort algorithm
 * to sort an array in ascending order.
 */
void counting_sort(int *array, size_t size)
{
	int *a_algo, *b_algo, iMax, iNum;
	size_t i;

	if (size < 2 || !array)
		return;

	iMax = find_array_max(array, size);

	a_algo = malloc(sizeof(size_t) * (iMax + 1));
	b_algo = malloc(sizeof(int) * size);

	for (i = 0; (int)i <= iMax; i++)
		a_algo[i] = 0;
	for (i = 0; i < size; i++)
	{
		iNum = array[i];
		a_algo[iNum] += 1;
	}
	for (i = 1; (int)i <= iMax; i++)
		a_algo[i] += a_algo[i - 1];
	print_array(a_algo, iMax + 1);
	for (i = 0; i < size; i++)
	{
		b_algo[a_algo[array[i]] - 1] = array[i];
		a_algo[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = b_algo[i];
	free(b_algo);
	free(a_algo);
}
