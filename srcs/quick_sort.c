#include "sort.h"

static size_t partition(int arr[], size_t start, size_t end);
static void quick_sort_recursion(int arr[], size_t start, size_t end);

void quick_sort(int arr[], size_t size) {
	quick_sort_recursion(arr, 0, size - 1);
}

static void ft_coop(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static size_t partition(int arr[], size_t start, size_t end)
{
	int pivot_value = arr[end];
	size_t i = start;
	size_t j = start;

	while (j < end)
	{
		if (arr[j] <= pivot_value)
		{
			ft_coop(&arr[j], &arr[i]);
			++i;
		}
		++j;
	}
	ft_coop(&arr[i], &arr[end]);
	return (i);
}

void quick_sort_recursion(int arr[], size_t start, size_t end)
{
	if (start < end)
	{
		size_t i = partition(arr, start, end);
		if (i != 0)
			quick_sort_recursion(arr, start, i - 1);
		if (i + 1 < end)
			quick_sort_recursion(arr, i + 1, end);
	}
}