#include "sort.h"

/**
 * shell_sort - Sorts an array using shell sort (Knuth sequence)
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	/* Initialize the gap using the Knuth sequence */
	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* Continue with decreasing gap until it's 0 */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;

		}

		/* Calculate the next gap using the Knuth sequence */
		gap = (gap - 1) / 3;

		/* Print the array after each decrease in the gap */
		if (gap > 0)
		{
			print_array(array, size);
		}
	}

	/* Print the final sorted list */
	print_array(array, size);
}
