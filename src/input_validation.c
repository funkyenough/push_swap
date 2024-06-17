#include "./push_swap.h"

int	are_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	has_duplicates(int arr_size, int *intarr)
{
	int i;
	int j;

	i = 0;
	while (i < arr_size)
	{
		j = i + 1;
		while (j < arr_size)
		{
			if (intarr[i] == intarr[j])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}