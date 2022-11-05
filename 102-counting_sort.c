#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, idx;
	size_t i;
	int *count, *ordered;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size; i++)
		if (k < array[i])
			k = array[i];

	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)k; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);

	ordered = malloc(sizeof(int) * size);
	if (ordered == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		idx = count[array[i]]--;
		ordered[idx - 1] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = ordered[i];

	free(ordered);
	free(count);
}
