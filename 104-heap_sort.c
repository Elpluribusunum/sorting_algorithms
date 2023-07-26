#include "sort.h"

/**
 * iParent - returns the parent node's index for a binary array
 * for index i in tree
 * @i: to determine parent node index, use the starting index.
 * Return: the parent node's index.
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild- provide the left child branch index 4 an array dat is set up as
 * a binary tree, where i is the index.
 * @i: to find the left child branch index, start index.
 * Return: the left child node's index.
 */
int iLeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * ConvertToHeap - array of no is organ into a heap or binary tree architect.
 * @array: multiple integers.
 * @size: array size in elements.
 */
void ConvertToHeap(int *array, size_t size)
{
	int start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		SiftDown(array, size, start, size - 1);
		start--;
	}
}

/**
 * SiftDown - arrays sorted by heap/binary tree are shuffle into array sorted
 * going up in value
 * @array: array of data to be sorted immediately, rising from heap.
 * @size: amount of array items.
 * @start: beginning index
 * @end: final index
 */
void SiftDown(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;

	root = start;

	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - utilizin a heap sort, sort an array of integer in ascending orde
 * sifting algorithm.
 * @array: sorted array of values.
 * @size: amount of array items.
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	ConvertToHeap(array, size);

	iEnd =  (int)size - 1;
	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		SiftDown(array, size, 0, iEnd);
	}
}
