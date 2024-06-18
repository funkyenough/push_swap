#include "./push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*new_node;

	if (!*a || !(*a)->next)
		return ;
	new_node = *a;
	*a = (*a)->next;
	new_node->next = NULL;
	stack_add_tail(a, new_node);
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}