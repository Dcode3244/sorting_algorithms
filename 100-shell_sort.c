#include "sort.h"

/**
 * shell_sort - sorts array of integers in ascending order using
 * the Shell sort algorithm, using Knuth sequence
 * @array: the array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int i, j, gap = 1, temp;

	while (gap < (int)size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < (int)size; i += 1)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp);
					j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
