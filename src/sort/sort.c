#include "../push_swap.h"

int	stack_max_value(t_stack *stack)
{
	int	max;

	max = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	stack_min_value(t_stack *stack)
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
	if (stack_min_value(*stack) == (*stack)->value)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack_min_value(*stack) == second->value)
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

int	find_value_position(t_stack **stack, int value)
{
	int	position;
	t_stack *temp;

	temp = *stack;

	position = 0;
	while (temp)
	{
		if (temp->value == value)
			return (position);
		position++;
		temp = temp->next;
	}
	return (position);
}

void	push_min(t_stack **a, t_stack **b, int position)
{
	if (position == 1)
		sa(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
	{
		ra(a);
		ra(a);
		ra(a);
	}
	else if (position == 4)
		rra(a);
	pb(a, b);
}
void	sort_four(t_stack **a, t_stack **b)
{
	int	position;

	position = find_value_position(a, stack_min_value(*a));
	push_min(a, b, position);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	position;

	position = find_value_position(a, stack_min_value(*a));
	push_min(a, b, position);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small(t_stack **a)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	// if (size == 4)
	// 	sort_four(a, b);
	// if (size == 5)
	// 	sort_five(a, b);
	return ;
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

void	sort(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	// print_stacks(*stack_a, stack_b);
	if (!is_sorted(*stack_a))
	{
		// if (stack_size(*stack_a) < 3)
			// sort_small(stack_a, &stack_b);
		// else
		// 	radix_sort(stack_a, &stack_b);
			quicksort(stack_a, &stack_b, stack_size(*stack_a));
	}
	// print_stacks(*stack_a, stack_b);

	// if (stack_a)
	// 	stack_clear(stack_a);
	// if (stack_b)
	// 	stack_clear(&stack_b);
}