#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending order
 *			Uses Selection sort algorithm
 * @array: Array to sort
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t min_index, i, j;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Find index of minimum element in unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		/* Swap current element with minimum element */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
