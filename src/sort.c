/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:03 by yinhong           #+#    #+#             */
/*   Updated: 2024/06/18 20:01:04 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a)
{
	int		max;
	int		max_bits;
	int		current_bit;
	t_stack	*stack_b;

	max = max_stack_value(*stack_a);
	max_bits = count_bits(max);
	current_bit = max_bits;
	while (*stack_a)
	{
		if (get_bit((*stack_a)->value, current_bit) == 0)
			pb(stack_a, &stack_b);
		else
			ra(stack_a);
		*stack_a = (*stack_a)->next;
		ft_printf("Current top address:%p\n", stack_a);
	}
	stack_clear(stack_a);
	stack_clear(&stack_b);
}
int	count_bits(int i)
{
	int	bits;

	bits = 0;
	while (i)
	{
		i /= 2;
		bits++;
	}
	return (bits);
}

int	get_bit(int i, int bit_requested)
{
	return ((i >> bit_requested) & 1);
}

int	max_stack_value(t_stack *stack)
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
		else
			radix_sort(stack);
	}
	print_stack(*stack, AFTER);
}