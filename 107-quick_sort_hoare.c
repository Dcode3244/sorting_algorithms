#include "sort.h"

int partition(int *array, int lo, int hi, size_t size);
void _quick_sort(int *array, int lo, int hi, size_t size);
void swap(int *a, int *b);
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - partitions and sorts an array
 * @array: the array to be sorted
 * @size: size of the array
 * @hi: highest index of the partitioned array
 * @lo: lowest index of the partitioned array
 */
void _quick_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (hi > lo)
	{
		p = partition(array, lo, hi, size);

		_quick_sort(array, lo, p - 1, size);
		_quick_sort(array, p, hi, size);
	}
}

/**
 * partition - partitions an array
 * @array: the array to be sorted
 * @lo: lowest index of the array
 * @hi: highest index of the array
 * @size: size of the array
 * Return: pivot point
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pvt;

	pvt = array[hi];
	i = lo - 1;
	j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pvt);

		do {
			j--;
		} while (array[j] > pvt);

		if (i >= j)
			return (i);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * swap - swaps values of two numbers
 * @a: the first number
 * @b: the second number
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
