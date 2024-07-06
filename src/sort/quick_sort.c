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

    // Rotate back the elements that were not moved
    for (i = 0; i < size - elements_moved; i++)
        rra(a);

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

    ft_printf("\n--- Quicksort called ---\n");
    ft_printf("Stack A: ");
    print_stack(*a, NONE);
    ft_printf("Stack B: ");
    print_stack(*b, NONE);
    ft_printf("Size: %d\n", size);

    if (size <= 1)
        return;

    if (size <= 3)
    {
        ft_printf("Sorting small stack (size <= 3)\n");
        sort_small(a);
        ft_printf("After sort_small:\n");
        ft_printf("Stack A: ");
        print_stack(*a, NONE);
        ft_printf("Stack B: ");
        print_stack(*b, NONE);
        return;
    }

    pivot = choose_pivot(a);
    ft_printf("Chosen pivot: %d\n", pivot);

    elements_moved = partition(a, b, size, pivot);
    ft_printf("Partitioned %d elements\n", elements_moved);
    ft_printf("After partition:\n");
    ft_printf("Stack A: ");
    print_stack(*a, NONE);
    ft_printf("Stack B: ");
    print_stack(*b, NONE);

    // Sort the smaller partition (in B)
    quicksort(b, a, elements_moved);

    // Sort the larger partition (remaining in A)
    quicksort(a, b, size - elements_moved);

    // Move sorted elements from B back to A
    while (elements_moved--)
        pa(a, b);

    ft_printf("Quicksort completed for this call\n");
    ft_printf("Final state:\n");
    ft_printf("Stack A: ");
    print_stack(*a, NONE);
    ft_printf("Stack B: ");
    print_stack(*b, NONE);
}