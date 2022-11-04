#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int temp, swap;
	size_t i, j, idx;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		temp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (temp < array[j])
				continue;
			temp = array[j];
			idx = j;
			swap = 1;
		}
		array[idx] = array[i];
		array[i] = temp;
		if (swap == 1)
			print_array(array, size);
	}
}
