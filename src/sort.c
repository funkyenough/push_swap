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
	// ft_printf("min is: %d\n", min);
	return (min);
}

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_three(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	second = (*stack)->next;
	third = (*stack)->next->next;
	if (min_stack_value(*stack) == (*stack)->value)
	{
		sa(stack);
		ra(stack);
	}
	else if (min_stack_value(*stack) == second->value)
	{
		if ((*stack)->value > third->value)
			ra(stack);
		else
			sa(stack);
	}
	else
	{
		if ((*stack)->value > second->value)
		{
			sa(stack);
			rra(stack);
		}
		else
			rra(stack);
	}
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

void	sort(t_stack **stack)
{
	print_stack(*stack, BEFORE);
	if (!is_sorted(*stack))
	{
		if (stack_size(*stack) == 2)
			sort_two(stack);
		if (stack_size(*stack) == 3)
			sort_three(stack);
	}
	print_stack(*stack, AFTER);
}