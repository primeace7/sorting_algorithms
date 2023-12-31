#include "sort.h"

/**
 * shell_sort - sort an array of integers using shell sort
 * @array: pointer to the array to sort
 * @size: the number of elements in @array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int gap, count, n, j, hold, gap_array[10];

	count = 9; /*10 elements will be generated in gap_array*/
	n = 1;
	hold = 0;

	for (; count >= 0; count--)
	{
		gap_array[count] = n;
		n = n * 3 + 1;
	}

	for (count = 0; count < 10; count++)
	{
		gap = gap_array[count];

		if (((int)size) > gap)
		{
			for (n = gap; n < (int)size; n += gap)
			{
				j = n;

				for (; array[j] < array[j - gap]; j -= gap)
				{
					hold = array[j];
					array[j] = array[j - gap];
					array[j - gap] = hold;
				}
			}
			print_array(array, size);
		}
	}
}
