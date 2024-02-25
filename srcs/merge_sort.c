#include "sort.h"

void merge_sort(int arr[], size_t p, size_t r);
static void merge(int arr[], size_t p, size_t q, size_t r);
static int *iarrdup(int arr[], size_t size);
static void swap_ints(int *a, int *b);

void merge_sort(int arr[], size_t p, size_t r)
{
	(void)swap_ints;
	if ((r - p) == 0 || p >= r)
		return ;
	size_t q = (r + p) / 2;
	merge_sort(arr, p, q);
	merge_sort(arr, q + 1, r);
	merge(arr, p, q, r);
}

static void merge(int arr[], size_t p, size_t q, size_t r)
{
	int *arr1 = iarrdup(arr, q - p + 1);
	int *arr2 = iarrdup(arr + q + 1, r - q);
	size_t i = p;
	size_t i1 = 0;
	size_t i2 = 0;

	while (i1 < q - p + 1 && i2 < r - q)
	{
		if (arr1[i1] <= arr2[i2])
		{
			arr[i] = arr1[i1];
			++i1;
		}
		else
		{
			arr[i] = arr2[i2];
			++i2;
		}
		++i;
	}

	while (i1 < q - p + 1)
		arr[i++] = arr1[i1++];
	while (++i2 < r - q)
		arr[i++] = arr2[i2++];

	(free(arr1), free(arr2));
}

static int *iarrdup(int arr[], size_t size)
{
	size_t i = -1;
	int *self = malloc(sizeof(int) * size);

	while (++i < size)
		self[i] = arr[i];
	return (self);
}

static void swap_ints(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
