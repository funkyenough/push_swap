#include "./push_swap.h"

void	swap(t_stack *a, t_stack *b)
{
	int	buf;

	if (!a || !b)
		return ;
	buf = a->value;
	a->value = b->value;
	b->value = buf;
}

void	sa(t_stack *a)
{
	swap(a, a->next);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b, b->next);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}