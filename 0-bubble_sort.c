#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, x;
	int temp, swap = 0;

	if (array == NULL || *array == NULL || size < 2)
		return;

	for (x = 1; x < size; x++)
	{
		for (i = 0; i < size - x; i++)
		{
			if (array[i] < array[i + 1])
				continue;
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
			swap = 1;
		}
		if (swap == 0)
			break;
		swap = 0;
	}
}
