#include "./push_swap.h"

void	rrotate(t_stack **a)
{
	t_stack	*new_node;

	if (!*a || !(*a)->next)
		return ;
	new_node = stack_last(*a);
	stack_add_front(a, new_node);
	stack_delone(new_node);
}

void	rra(t_stack **a)
{
	rrotate(a);
}

void	rrb(t_stack **b)
{
	rrotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}