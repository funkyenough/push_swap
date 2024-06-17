#include "push_swap.h"

// radix_sort (t_stack *stack_a, t_stack *stack_b)
// {

// }

int	min_stack_value(t_stack *stack)
{
	int	min;

	min = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	ft_printf("min is: %d\n", min);
	return (min);
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->value > stack_a->next->value)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	
	// if (min_stack_value(stack_a) == (int)stack_a->value)
	// {
		ft_printf("min stack value: %d\n", min_stack_value(stack_a));
		sa(stack_a);
		ra(&stack_a);
	// }
	// else
	// {
	// 	if ()
	// }
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

void	sort(t_stack *stack_a)
{
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sort_two(stack_a);
		if (stack_size(stack_a) == 3)
			sort_three(stack_a);
	}
}