#include "sort.h"

void init_rad(int **rad, int *counter, int *dup);
void swap(int **rad, int *array, int *counter, int size);
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int i, **rad, *dup, counter[10], j;
	int mod = 10, div = 1, largest = 0;

	if (size < 2 || array == NULL)
		return;
	dup = malloc(sizeof(int) * size);
	if (dup == NULL)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > largest)
			largest = array[i];
	}

	while (largest / div > 0)
	{
		for (i = 0; i < 10; i++)
			counter[i] = 0;

		for (i = 0; i < (int)size; i++)
			counter[(array[i] % mod) / div]++;

		rad = malloc(sizeof(int *) * 10);
		if (rad == NULL)
		{
			free(dup);
			return;
		}
		init_rad(rad, counter, dup);

		for (i = 0; i < (int)size; i++)
			dup[i] = (array[i] % mod) / div;

		for (i = 0; i < (int)size; i++)
		{
			if (*rad[dup[i]] == -1)
				*rad[dup[i]] = array[i];
			else
			{
				for (j = 0; rad[dup[i]][j] != -1; j++)
					;
				rad[dup[i]][j] = array[i];
			}
		}
		swap(rad, array, counter, size);
		mod *= 10;
		div *= 10;

		for (i = 0; i < 10; i++)
		{
			if (rad[i] != NULL)
				free(rad[i]);
		}
		free(rad);
	}
	free(dup);
}

/**
 * init_rad - initializes storage bucket for the array according
 * to the numbers LSD
 * @rad: the storage bucked
 * @counter: number of repetition for each LSD
 * @dup: array containing the swaping index of the original
 * array
 */
void init_rad(int **rad, int *counter, int *dup)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		if (counter[i] == 0)
			rad[i] = NULL;
		else
		{
			rad[i] = malloc(sizeof(int) * counter[i]);
			if (rad[i] == NULL)
			{
				for (; i >= 0; i--)
				{
					if (rad[i] != NULL)
						free(rad[i]);
				}
				free(rad);
				free(dup);
				return;
			}
			for (j = 0; j < counter[i]; j++)
				rad[i][j] = -1;
		}
	}

}

/**
 * swap - swaps the array values by the arranged bucket values
 * @rad: the bucket
 * @array: the array to be sorted
 * @counter: number of repetition for rach LSD
 * @size: size of the array
 */
void swap(int **rad, int *array, int *counter, int size)
{
	int k = 0, i, j, swap = 0;

	for (i = 0; i < 10; i++)
	{
		if (rad[i] == NULL)
			continue;
		for (j = 0; j < counter[i]; j++, k++)
		{
			if (array[k] != rad[i][j])
			{
				array[k] = rad[i][j];
				swap = 1;
			}
		}
	}
	if (swap == 1)
		print_array(array, size);
}
