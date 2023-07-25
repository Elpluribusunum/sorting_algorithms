#include "sort.h"


/**
 * swap_ints -  In the array, insert two integers.
 * @a:  The first integer that will be exchanged.
 * @b:  The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;


	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - Integer arrays should be sorted ascending
 * utilizing the shell sort algorithm to arrange.
 * @array: a collection of integers.
 * @size: The array's dimensions.
 *
 * Description: use the Knuth interval hierarchy.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;


	if (array == NULL || size < 2)
		return;


	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;


	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
