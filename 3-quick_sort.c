#include "sort.h"

/**
 * q_sort - implementation of the quicksort algorithm
 * @array: pointer to the array to sort
 * @start: the start index of the array range to sort
 * @end: the end index of the array range to sort
 */

void q_sort(int *array, int start, int end, size_t size)
{
        int p_index;

        if (start < end)
	{
		p_index = partition(array, start, end, size);
		q_sort(array, start, p_index - 1, size);
		q_sort(array, p_index + 1, end, size);
	}
}

/**
 * quick_sort - implementation of the quicksort algorithm via helper
 * function
 * @array: pointer to the array to sort
 * size: the number of elements in @array
 */

void quick_sort(int *array, size_t size)
{
	int start, end;

	start = 0;
	end = (int) (size - 1);
	q_sort(array, start, end, size);
}

int partition(int *A, int start, int end, size_t size)
{
	int i, p_index, pivot;

	pivot = A[end];
	p_index = start;

	for (i = start; i < end; i++)
	{
		if (A[i] <= pivot)
		{
			swap(A + i, A + p_index);
			p_index++;
		}
	}

	swap(A + end, A + p_index);
	print_array(A, size);
	return p_index;
}

void swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
