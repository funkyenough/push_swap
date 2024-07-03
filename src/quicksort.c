#include "push_swap.h"

int	partition(t_stack **a, t_stack **b, int size)
{
	int pivot;
	int	element;
	int	i;

	pivot = (*a)->value;
	element = 0;
	i = 0;
	while (i < size)
	{
		if ((*a)->value < pivot)
		{
			pb(a, b);
			element++;
		}
		else
			ra(a);
		i++;
	}
	return (element);
}

int	get_median(int first, int middle, int last)
{
	if ((first <= middle && middle <= last) || (last <= middle
			&& middle <= first))
		return (middle);
	if ((middle <= first && first <= last) || (last <= first
			&& first <= middle))
		return (first);
	return (last);
}

int	choose_pivot(t_stack **a)
{
	int		first;
	int		middle;
	int		last;
	int		size;
	t_stack	*temp;

	temp = *a;
	first = (*a)->value;
	last = stack_get_tail(*a)->value;
	size = stack_size(*a) / 2;
	while (size > 0)
	{
		temp = temp->next;
		size--;
	}
	middle = temp->value;
	return (get_median(first, middle, last));
}

void	quicksort(t_stack **a, t_stack **b, int size)
{
	int pivot;
	int element;

	ft_printf("Quicksort called with size %d\n", size);
	if (size <= 3)
	{
		ft_printf("Sorting small stack (size <= 3)\n");
		sort_small(a);
		return ;
	}
	pivot = choose_pivot(a);
	ft_printf("Chosen pivot: %d\n", pivot);
	element = partition(a, b, size);
	ft_printf("Partitioned %d elements\n", element);
	quicksort(a, b, element);
	quicksort(a, b, size - element - 1);
	while (element--)
		pa(b, a);
	ft_printf("Quicksort completed for this call\n");
}