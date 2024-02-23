#include "sort.h"

void	swap_ints(int *a, int *b);
void	fetch_input(int c, char **v, int arr[]);
void	print_array(int arr[], size_t size);

int main(int c, char **v) {
	int arr[c - 2];
	++v;
	fetch_input(c - 1, ++v, arr);
	if (!strncmp(*--v, "b", 2))
		bubble_sort(arr, c - 2);
	else if (!strncmp(*v, "q", 2))
		quick_sort(arr, c - 2);
	print_array(arr, c - 2);
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
