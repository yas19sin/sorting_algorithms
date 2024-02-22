#include "sort.h"

/**
 * func_left_right - Print left and right partitions of an array.
 * @args: The array to print partitions from.
 * @size: The size of the array.
 * @first: The initial position of the partition.
 * @nos: The middle position dividing the partitions.
 */
void func_left_right(int *args, int size, int first, int nos)
{
	int index;

	printf("Merging...\n");
	printf("[left]: ");
	index = first;
	while (index < nos)
	{
		if (index != nos - 1)
			printf("%d, ", args[index]);
		else
			printf("%d\n", args[index]);
		index++;
	}

	printf("[right]: ");
	index = nos;
	while (index < size)
	{
		if (index < size - 1)
			printf("%d, ", args[index]);
		else
			printf("%d\n", args[index]);
		index++;
	}
}

/**
 * merge_values - Merge the values in the position of an array.
 * @args: The first array to merge.
 * @sz: The size of the array.
 * @start: The initial position.
 * @nos: The middle position.
 * @copy: A copy of the array.
 */
void merge_values(int *args, int sz, int start, int nos, int *copy)
{
	int index, j, i;

	func_left_right(args, sz, start, nos);

	i = start;
	j = nos;

	printf("[Done]: ");
	index = start;
	while (index < sz)
	{
		if (i < nos && (j >= sz || args[i] <= args[j]))
		{
			copy[index] = args[i];
			i++;
		}
		else
		{
			copy[index] = args[j];
			j++;
		}
		if (index < sz - 1)
			printf("%d, ", copy[index]);
		else
			printf("%d\n", copy[index]);
		index++;
	}
}

/**
 * merge_sorts - Array separator for merge sort.
 * @copy: A copy of the array.
 * @start: The initial position.
 * @size: The size of the original array.
 * @args: The original array.
 */
void merge_sorts(int *copy, int start, int size, int *args)
{
	int nos;

	if (size - start < 2)
		return;

	nos = (size + start) / 2;

	merge_sorts(args, start, nos, copy);
	merge_sorts(args, nos, size, copy);
	merge_values(copy, size, start, nos, args);
}

/**
 * args_copy - Copy an array of integers.
 * @args: The source array.
 * @copy: The destination array.
 * @size: The size of the array.
 */
void args_copy(int *args, int *copy, int size)
{
	int index;

	for (index = 0; index < (int)size; index++)
		copy[index] = args[index];
}

/**
 * merge_sort - Create partitions and perform merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *copy;

	copy = malloc(sizeof(int) * size - 1);

	if (copy == NULL)
		return;

	args_copy(array, copy, size);

	merge_sorts(copy, 0, size, array);
	free(copy);
}
