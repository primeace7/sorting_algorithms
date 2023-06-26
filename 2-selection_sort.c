#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 * @array: pointer to the array to sort
 * @size: the number of elements in @array
 * Returns: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min_value;

	for (i = 0; i < size; i++)
	{
		min_value = array[i];
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min_value)
			{
				min_index = j;
				min_value = array[j];
			}
		}

		if(min_index != i)
		{
			array[min_index] = array[min_index] ^ array[i];
			array[i] = array[i] ^ array[min_index];
			array[min_index] = array[min_index] ^ array[i];
			print_array(array, size);
		}
	}
}
