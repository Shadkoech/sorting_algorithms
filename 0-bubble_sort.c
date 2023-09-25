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
	int temp;
	size_t i, j;

	if (size < 2 || array == NULL)
		return;

	/* Loop through the array multiple times */
	for (i = 0; i < size - 1; i++)
	{
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

				print_array(array, size);
			}
		}
	}
}
