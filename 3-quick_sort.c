#include "sort.h"

/**
 * lomuto_partition - A function that partitions the array
 * @array: pointer to the array to partition
 * @low: low
 * @high: high
 * @size: size of the array
 * Return: number of changes made
 **/
int lomuto_partition(int *array, int high, int low, size_t size)
{
	int pivot, i, index, temp;

	pivot = array[high];
	index = low;
	i = 0;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (index != i)
			{
				temp = array[i];
				array[i] = array[index];
				array[index] = temp;
				print_array(array, size);
			}
			index++;
		}
	}
	if (index != high)
	{
		temp = array[high];
		array[high] = array[index];
		array[index] = temp;
		print_array(array, size);
	}
	return (index);
}

/**
 *quick_sort - Function that applies Quick sort Algorithm to
 *      sort an array of integers in ascending order
 *@array: The array holding the integers to sort
 *@size: The size of the array to sort
 *
 *Return: void
 */
void quick_sort(int *array, size_t size)
{
	int low, high, pivotIndex;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;

	while (low < high)
	{
		pivotIndex = lomuto_partition(array, high, low, size);
		if (pivotIndex < low + high - pivotIndex)
		{
			quick_sort(array + low, pivotIndex - low);
			low = pivotIndex + 1;
		}
		else
		{
			quick_sort(array + pivotIndex + 1, high - pivotIndex);
			high = pivotIndex - 1;
		}
	}
}
