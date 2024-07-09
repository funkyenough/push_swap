#include "push_swap.h"

void	swap_array(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int *arrange_index(int *intarr, int size)
{
	int *tmp;
	int i;
	int j;

	i = 0;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return NULL;
	while (i < size)
	{
		tmp[i] = intarr[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp[i] > tmp[j])
				swap_array(&tmp[i], &tmp[j]);
			j++;
		}
		i++;
	}
	return tmp;
}

int *get_index(int *intarr, int size)
{
	int *index;
	int *sorted;
	int i;
	int j;

	sorted = arrange_index(intarr, size);
	if (sorted == NULL)
		return NULL;
	index = (int *)malloc(sizeof(int) * size);
	if (index == NULL)
	{
		free(sorted);
		return NULL;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (sorted[i] == intarr[j])
			{
				index[j] = i;
				break;
			}
			j++;
		}
		i++;
	}
	free(sorted);
	return index;
}

// int main() {
//     int intarr[] = {5, 3, 1, 4, 2};
//     int size = sizeof(intarr) / sizeof(intarr[0]);
//     int *sorted;
//     int *index;
//     int i;

//     ft_printf("Original array:\n");
//     for (i = 0; i < size; i++) {
//         ft_printf("%d ", intarr[i]);
//     }
//     ft_printf("\n");

//     sorted = arrange_index(intarr, size);
//     if (sorted == NULL) {
//         ft_printf("Failed to sort the array.\n");
//         return 1;
//     }

//     ft_printf("Sorted array:\n");
//     for (i = 0; i < size; i++) {
//         ft_printf("%d ", sorted[i]);
//     }
//     ft_printf("\n");

//     index = get_index(intarr, size);
//     if (index == NULL) {
//         ft_printf("Failed to get index array.\n");
//         free(sorted); // Clean up allocated memory
//         return 1;
//     }

//     ft_printf("Index array:\n");
//     for (i = 0; i < size; i++) {
//         ft_printf("%d ", index[i]);
//     }
//     ft_printf("\n");

//     free(sorted); // Clean up allocated memory
//     free(index); // Clean up allocated memory

//     return 0;
// }