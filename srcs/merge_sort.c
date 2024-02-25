#include "sort.h"

void merge_sort(int arr[], size_t p, size_t r);
static void merge_(int arr[], size_t p, size_t q, size_t r);

void merge_sort(int arr[], size_t p, size_t r)
{
	if ((r - p) == 0 || p >= r)
		return ;
	size_t q = (r + p) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge_(arr, p, q, r);
}

void merge_(int arr[], size_t start, size_t mid, size_t end)
{
	size_t p, q, i;
	int *temp = malloc(sizeof(int) * (end - start + 1));
	i = 0;
	p = start;
	q = mid + 1;
	while (p <= mid && q <= end)
	{
		if (arr[p] < arr[q])
			(temp[i] = arr[p], ++p);
		else
			(temp[i] = arr[q], ++q);
		++i;
	}

	while (p <= mid)
		(temp[i++] = arr[p], ++p);
	while (q <= end)
		(temp[i++] = arr[q], ++q);
	i = 0;
	p = start;
	while (p <= end)
		arr[p++] = temp[i++];
}
