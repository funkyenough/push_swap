#include "./push_swap.h"
#include <stdio.h>

void	push(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (*b)
	{
		node = stack_last(*b);
		stack_add_front(a, node);
		stack_delone(node);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
}