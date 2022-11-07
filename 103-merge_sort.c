#include "sort.h"

void merge_recursive(int *array, int *temp, size_t size);
void merge(int *array, int *temp, int m, size_t size);

/**
 * merge_sort - merges an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_recursive(array, temp, size);
	free(temp);
}

/**
 * merge_recursive - divides and sorts the array recursively
 * @array: the array to be sorted
 * @temp: temporary array to store sorted values
 * @size: size of the array
 */
void merge_recursive(int *array, int *temp, size_t size)
{
	size_t m;

	if (size < 2)
		return;

	m = size / 2;
	merge_recursive(array, temp, m);
	merge_recursive(array + m, temp + m, size - m);

	merge(array, temp, m, size);
}


/**
 * merge - sorts the array
 * @array: the array to be sorted
 * @temp: temporary array to store sorted values
 * @m: mid part of the array
 * @size: size of the array
 */
void merge(int *array, int *temp, int m, size_t size)
{
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, m);
	printf("[right]: ");
	print_array(array + m, size - m);

	for (i = 0; i < (int)size; i++)
	{
		if ((array[j] < array[m + k] && j < m) || k >= (int)size - m)
		{
			temp[i] = array[j];
			j++;
		}
		else
		{
			temp[i] = array[m + k];
			k++;
		}
	}
	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, size);
}
