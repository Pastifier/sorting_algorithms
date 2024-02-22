#include "sort.h"

static size_t partition(int arr[], size_t start, size_t end);

void quick_sort(int arr[], size_t start, size_t end) {
	size_t i;

	i = partition(arr, start, end);

	if (i < end)
	{
		quick_sort(arr, i, end);
		quick_sort(arr, start, i - 1);
	}
}

static void ft_coop(int *a, int *b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

static size_t partition(int arr[], size_t start, size_t end) {
	size_t pivot = end;
	while (start < end)
	{
		while (arr[start] < arr[pivot])
			++start;
		while (arr[end] >= arr[pivot] && end > start)
			--end;
		if (start < end)
			ft_coop(&arr[start], &arr[end]);
	}
	ft_coop(&arr[start], &arr[pivot]);
	return (start);
}
