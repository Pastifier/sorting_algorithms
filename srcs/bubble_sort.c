#include "sort.h"

void	swap_ints(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	bubble_sort(int arr[], size_t size) {
	bool did_swap = true;
	size_t i;

	while (did_swap)
	{
		did_swap = false;
		i = 0;
		while (++i <= size)
		{
			if (arr[i - 1] > arr[i])
			{
				swap_ints(&arr[i - 1], &arr[i]);
				did_swap = true;
			}
		}
	}
}
