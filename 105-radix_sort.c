#include "sort.h"

/**
 * max_array - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max_array(int *array, int size)
{
	int i, iMax;

	for (iMax = array[0], i = 1; i < size; i++)
	{
		if (array[i] > iMax)
			iMax = array[i];
	}
	return (iMax);
}

/**
 * sort_radix - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @args: An array of integers.
 * @size: The size of the array.
 * @digit: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void sort_radix(int *args, size_t size, int digit, int *buffer)
{
	int iCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		iCount[(args[i] / digit) % 10] += 1;

	for (i = 0; i < 10; i++)
		iCount[i] += iCount[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buffer[iCount[(args[i] / digit) % 10] - 1] = args[i];
		iCount[(args[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		args[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int iMax, digit, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

	if (buffer == NULL)
		return;

	iMax = max_array(array, size);

	for (digit = 1; iMax / digit > 0; digit *= 10)
	{
		sort_radix(array, size, digit, buffer);
		print_array(array, size);
	}

	free(buffer);
}
