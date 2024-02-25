#ifndef SORT_H
# define SORT_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	bubble_sort(int arr[], size_t size);
void	quick_sort(int arr[], size_t size);
void	merge_sort(int arr[], size_t p, size_t r);

#endif // !SORT_H
