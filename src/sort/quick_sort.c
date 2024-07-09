#include "../push_swap.h"

int partition(t_stack **a, t_stack **b, int size, int pivot)
{
    int i;
    int elements_moved = 0;

    for (i = 0; i < size; i++)
    {
        if ((*a)->value < pivot)
        {
            pb(a, b);
            elements_moved++;
        }
        else
            ra(a);
    }
    return elements_moved;
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

void quicksort(t_stack **a, t_stack **b, int size)
{
    int pivot;
    int elements_moved;

    if (size <= 1)
        return;

    if (size <= 3)
    {
        sort_small(a, b);
        return;
    }

    pivot = choose_pivot(a);

    elements_moved = partition(a, b, size, pivot);

    // Sort the smaller partition (in B)
    quicksort(b, a, elements_moved);

    // Sort the larger partition (remaining in A)
    quicksort(a, b, size - elements_moved);

    // Move sorted elements from B back to A
    while (elements_moved--)
        pa(a, b);
}