

#include "sort.h"

/**
 * swap - swaps two integers
 * @first: first integer
 * @second: second integer
 */
void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * lomuto_partition - partitions array using lomuto scheme
 * @arr: array to partition
 * @size: size of array
 * @low: low index
 * @high: high index
 * Return: index of pivot
 */
int lomuto_partition(int *arr, size_t size, ssize_t low, ssize_t high)
{
	ssize_t j, i;
	int pivot;
	
	pivot = arr[high];

	i = low;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}

	swap(&arr[i], &arr[high]);

	return (i);
}

/**
 * lomuto_scheme - sorts array using lomuto scheme
 * @arr: array to sort
 * @size: size of array
 * @low: low index
 * @high: high index
 */
void lomuto_scheme(int *arr, size_t size, ssize_t low, ssize_t high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(arr, size, low, high);

		lomuto_scheme(arr, size, low, pivot - 1);
		lomuto_scheme(arr, size, pivot + 1, high);
	}
}

/**
 * quick_sort - sorts array using quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	lomuto_scheme(array, size, 0, size - 1);
}
