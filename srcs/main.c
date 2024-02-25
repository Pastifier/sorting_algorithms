#include "sort.h"

void	swap_ints(int *a, int *b);
void	fetch_input(int c, char **v, int arr[]);
void	print_array(int arr[], size_t size);

int main(int c, char **v) {
	if (c < 3)
		return (0);
	if (c <= 2)
		return (-1);
	size_t arr_size = c - 2;
	int *arr = malloc(sizeof(int) * arr_size);
	++v;
	fetch_input(c - 1, ++v, arr);
	if (!strncmp(*--v, "b", 2))
		bubble_sort(arr, arr_size);
	else if (!strncmp(*v, "q", 2))
		quick_sort(arr, arr_size);
	else if (!strncmp(*v, "m", arr_size))
		merge_sort(arr, 0, arr_size - 1);
	print_array(arr, arr_size);
	free(arr);
	return (0);
}

void fetch_input(int c, char **v, int arr[]) {
	size_t i = -1;

	while (*v && ++i <= (size_t)c)
		arr[i] = atoi(*v++);
}

void print_array(int arr[], size_t size) {
	size_t i = -1;

	while (++i < size)
		printf("%d\n", arr[i]);
}
