#include "push_swap.h"

void	print_stack(t_stack *stack, int state)
{
	if (state == BEFORE)
		ft_printf("Before sort:\n");
	else if (state == AFTER)
		ft_printf("--------------------\nAfter sort:\n");
	else
		ft_printf("\n");
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	if (state == BEFORE)
		ft_printf("\n--------------------\n");
	else if (state == AFTER)
		ft_printf("\n\nLeaks:\n");
	else
		ft_printf("\n");
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("stack_a: ");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->value);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	ft_printf("stack_b: ");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->value);
		stack_b = stack_b->next;
	}
	ft_printf("\n\n");
}