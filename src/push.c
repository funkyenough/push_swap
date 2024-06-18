#include "./push_swap.h"
#include <stdio.h>

void	push(t_stack **destination, t_stack **origin)
{
	t_stack	*tmp;

	if (*origin)
	{
		tmp = *origin;
		*origin = (*origin)->next;
		tmp->next = *destination;
		*destination = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}