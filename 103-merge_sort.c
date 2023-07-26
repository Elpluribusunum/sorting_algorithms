#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * PrintArray - displays an integer array for a range of indicators.
 * @array: print an array of values.
 * @iBeg: the initial index value.
 * @iEnd: expiration index value.
 */
void PrintArray(int *array, int iBeg, int iEnd)
{
	int i;

	for (i = iBeg; i < iEnd; i++)
		if (i < iEnd - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
}

/**
 * CopyArray - easy 1:1 copy from source to destination.
 * @source: sorted array of values.
 * @iBeg: the initial index value.
 * @iEnd: expiration index value.
 * @dest: array used to hold ordered integers.
 */
void CopyArray(int *source, int iBeg, int iEnd, int *dest)
{
	int i;

	for (i = iBeg; i < iEnd; i++)
		dest[i] = source[i];
}

/**
 * TopDownMerge - ascending value is used to order source subsection ("runs").
 * @source: sorted array of values.
 * @iBeg: starting index value left run.
 * @iMid: beginning run index value is correct.
 * @iEnd: appropriate run ending index value.
 * @dest: array used to hold ordered integers.
 */
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int i, j, k;

	i = iBeg, j = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	PrintArray(source, iBeg, iMid);
	printf("[right]: ");
	PrintArray(source, iMid, iEnd);
	/* While there are elements in the left or right runs... */
	for (k = iBeg; k < iEnd; k++)
	{
		/* If left run head exists and is <= existing right run head */
		if (i < iMid && (j >= iEnd || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	PrintArray(dest, iBeg, iEnd);
}

/**
 * TopDownSplitMerge - The merge_sort recursive engine serat d working copy of
 * array into runs on the left and right, then combines using TopDownMerge
 * @source: integer array that needs to be sorted.
 * @iBeg: the initial index value.
 * @iEnd: expiration index value.
 * @dest: array used to hold ordered integers.
 */
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (iEnd - iBeg < 2) /* if run size == 1 */
		return;     /* consider it sorted */
	/* split the run longer than 1 item into halves */
	iMid = (iEnd + iBeg) / 2;

	TopDownSplitMerge(dest, iBeg, iMid, source);  /* sort left run */
	TopDownSplitMerge(dest, iMid, iEnd, source);  /* sort right run */
	/* merge the resulting runs from array[] into work_copy[] */
	TopDownMerge(source, iBeg, iMid, iEnd, dest);
}

/**
 * merge_sort - utilizing a sort function, ascends an array of numbers
 * algorithm for top-down merge sorting
 * @array: integer array that needs to be sorted
 * @size: array size in elements
 */
void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);
	if (!work_copy)
		return;

	CopyArray(array, 0, size, work_copy);
	TopDownSplitMerge(work_copy, 0, size, array);

	free(work_copy);
}
