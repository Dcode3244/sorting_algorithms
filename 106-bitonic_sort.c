#include "sort.h"

void swap(int *a, int *b);
void _bitonic_sort(int *array, size_t size, size_t N, int lo, int direction);
void _bitonic_merge(int *array, size_t size, int lo, int direction);

#define INCR 1
#define DECR 0
/**
 * bitonic_sort - sorts an array of integers in ascending order using
 * using the Bitonic sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	_bitonic_sort(array, size, size, 0, INCR);
}


/**
 * _bitonic_sort - sorts an array of integers in ascending order recursively
 * @array: the array to be sorted
 * @size: size of the array
 * @N: the original size of the array
 * @lo: lowest point of the array
 * @direction: INCR(1) if increasing, DECR(0) if decreasing
 */
void _bitonic_sort(int *array, size_t size, size_t N, int lo, int direction)
{
	int half;

	if (size < 2)
		return;

	printf("Merging [%ld/%ld] (%s)\n", size, N,
			direction ? "UP" : "DOWN");
	print_array(array + lo, size);
	half = size / 2;
	_bitonic_sort(array, half, N, lo, INCR);
	_bitonic_sort(array, half, N, lo + half, DECR);
	_bitonic_merge(array, size, lo, direction);
	printf("Result [%ld/%ld] (%s)\n", size, N,
			direction ? "UP" : "DOWN");
	print_array(array + lo, size);
}

/**
 * _bitonic_merge - merges an array of integers in the given direction
 * @array: the array to be sorted
 * @size: size of the array
 * @lo: lowest point of the array
 * @direction: INCR(1) if increasing, DECR(0) if decreasing
 */
void _bitonic_merge(int *array, size_t size, int lo, int direction)
{
	int half, i;

	if (size < 2)
		return;

	half = size / 2;

	for (i = lo; i < lo + half; i++)
	{
		if (direction == (array[i] > array[half + i]))
			swap(&array[i], &array[half + i]);
	}
	_bitonic_merge(array, half, lo, direction);
	_bitonic_merge(array, half, lo + half, direction);
}

/**
 * swap - swaps two integer values
 * @a: the first int to be swaped
 * @b: the second int to be swaped
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
