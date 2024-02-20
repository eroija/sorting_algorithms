#include "sort.h"
/**
 * partition - Partitions the array using Lomuto scheme.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: size of array
 * Return: Index of the pivot element.
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (pivot != array[i])
	{
		temp = array[i];
		array[i] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_lomuto - helps quicksort implement the lomuto partition
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: array size
 */
void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t index; /* partition index */

	if (low < high)
	{
		index = partition(array, low, high, size);

		/* There is a left partition */
		if (index > 0)
			quick_sort_lomuto(array, low, index - 1, size);
		/* there is a right partition */
		if (index < high)
			quick_sort_lomuto(array, index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using Quick sort.
 * @array: Pointer to the array to be sorted.
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1 || array == NULL)
		return;
	quick_sort_lomuto(array, 0, size - 1, size);
}
