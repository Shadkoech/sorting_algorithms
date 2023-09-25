#include "sort.h"

/**
 * bubble_sort - Sorts integers array using bubble sort algorithm
 * @array: Pointer to array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	/* Loop through the array multiple times */
	for (i = 0; i < size - 1; i++)
	{
		/* No swaps yet(initialize to 0) */
		swapped = 0;
		/* Iterate through the unsorted array */
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Set swapped to 1(swap occurred) */
				swapped = 1;

				print_array(array, size);
			}
		}
		/* If no swaps, the array is already sorted */
		if (swapped == 0)
		{
			break;
		}
	}
}

