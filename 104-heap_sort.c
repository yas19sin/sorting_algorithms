#include "sort.h"

/**
 * heap - Perform sift down operation on a heap.
 * @args: The array containing the heap.
 * @size: The total size of the array.
 * @index: The index of the current node in the heap.
 * @mine: The index of the nth node in the heap to examine.
 */
void heap(int *args, size_t size, size_t index, size_t mine)
{
	size_t Higher, iLeft, iRight;

	do {
		iLeft = gotLeft(index);
		iRight = gotRight(index);
		Higher = index;

		if (iRight <= mine && args[iRight] > args[index])
			Higher = iRight;

		if (args[iLeft] > args[Higher])
			Higher = iLeft;

		if (index == Higher)
		return;

		args[index] ^= args[Higher];
		args[Higher] ^= args[index];
		args[index] ^= args[Higher];
		print_array(args, size);
		index = Higher;
	} while (gotLeft(index) <= mine);
}

/**
 * heap_sort - Sort an array using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t iNode, Passed;

	if (array == NULL || size < 2)
		return;

	for (iNode = gotParent(size - 1); iNode != SIZE_MAX; iNode--)
		heap(array, size, iNode, size - 1);

	for (Passed = size - 1; Passed > 1; Passed--)
	{
		array[0] ^= array[Passed];
		array[Passed] ^= array[0];
		array[0] ^= array[Passed];
		print_array(array, size);
		heap(array, size, 0, Passed - 1);
	}

	array[0] ^= array[1];
	array[1] ^= array[0];
	array[0] ^= array[1];
	print_array(array, size);
}
