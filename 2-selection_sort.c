#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 * @array: pointer to the array to sort
 * @size: the number of elements in @array
 * Returns: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_value;

	for (i = 0; i < size; i++)
	{
		min_value = array + i;

		for (j = i + 1; j < size; j++)
			if (array[j] < *min_value)
				min_value = array + j;

		if (min_value != i + array)
		{
			*min_value = *min_value ^ array[i];
			array[i] = array[i] ^ *min_value;
			*min_value = *min_value ^ array[i];
			print_array(array, size);
		}
	}
}
