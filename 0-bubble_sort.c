#include "sort.h"

/**
 * bubble_sort - implement the bubble sort algorithm
 * @array: pointer to the start address of the array to sort
 * @size: the number of elements in the array to sort
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, n;

	if (size < 2)
		return;
	swapped = 1;
	n = size;
	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < (n - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				swapped = 1;
				array[i] = array[i] ^ array[i + 1];
				array[i + 1] = array[i] ^ array[i + 1];
				array[i] = array[i] ^ array[i + 1];
				print_array(array, size);
			}
		}
		n--;
	}
}
