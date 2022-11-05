#include "sort.h"

void heapify(int *array, int N, int i, size_t size);
void swap(int *a, int *b);
/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	i = (size / 2) - 1;

	for (; i >= 0; i--)
		heapify(array, (int)size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}

}

/**
 * heapify - builds a heap from a given array
 * @array: the array to be built in to a heap
 * @N: number of unsorted array elements
 * @i: the index to be placed in correct maxheap position
 * @size: size of the array
 */
void heapify(int *array, int N, int i, size_t size)
{
	int largest, left, right;

	largest = i;
	left = largest * 2 + 1;
	right = largest * 2 + 2;

	if (left < N && array[left] > array[largest])
		largest = left;

	if (right < N && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, N, largest, size);
	}
}

/**
 * swap - swaps two values of an array
 * @a: the first number to be swaped
 * @b: the second number to be swaped
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
