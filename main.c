#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {127, 98, 124, 9, 153, 120, 113, 48, 140, 150, 87, 92, 45, 197, 112, 19, 141, 7, 88, 30, 184, 193, 176, 60, 100, 104, 111, 132, 42, 143, 8, 81, 188, 171, 79, 65, 25, 191, 51, 85, 123, 59, 74, 135, 119, 166, 181, 10, 21, 139};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
