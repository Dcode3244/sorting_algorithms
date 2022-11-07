#include "sort.h"


void swap(int *i, int *j);
void sorter(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int lo, hi;

	if (size < 2)
		return;

	lo = 0;
	hi = size - 1;

	sorter(array, lo, hi, size);
}


/**
 * sorter - sorts an array of integers in ascending order
 * using Quick sort algorithm
 * @lo: index 0 of the array
 * @hi: last index of the array
 * @array: the array to be sorted
 * @size: the size of the array
 */
void sorter(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo >= hi || lo < 0)
		return;
	p = partition(array, lo, hi, size);
	sorter(array, lo, p - 1, size);
	sorter(array, p + 1, hi, size);
}


/**
 * partition - creates partition of the array
 * @lo: least index of the partition
 * @hi: last index of the partition
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: returns index of pivot
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pvt = array[hi];
	int j, i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pvt)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i = i + 1;
	if (i != hi)
	{
		swap(&array[i], &array[hi]);
		print_array(array, size);
	}
	return (i);
}

/**
 * swap - swaps two values of given array index
 * @i: first value
 * @j: second value
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
