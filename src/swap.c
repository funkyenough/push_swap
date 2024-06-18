#include "./push_swap.h"

void	swap(t_stack **a)
{
	int	buf;

	if (!*a || !(*a)->next)
		return ;
	buf = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = buf;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}