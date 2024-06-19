/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:03 by yinhong           #+#    #+#             */
/*   Updated: 2024/06/19 09:58:43 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	int		max_bits;
	int		current_bit;
	t_stack	*first;

	first = NULL;
	max = max_stack_value(*stack_a);
	max_bits = count_bits(max);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		while (1)
		{
			if (*stack_a == first)
				break ;
			if (get_bit((*stack_a)->value, current_bit) == 0)
				pb(stack_a, stack_b);
			else
			{
				if (first == NULL)
					first = *stack_a;
				ra(stack_a);
			}
			// ft_printf("Current stack_a address:%p\n", *stack_a);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		first = NULL;
		current_bit++;
	}
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

void	sort(t_stack **stack_a)
{
	t_stack *stack_b;

	stack_b = NULL;
	// print_stacks(*stack_a, stack_b);
	if (!is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) == 2)
			sort_two(stack_a);
		if (stack_size(*stack_a) == 3)
			sort_three(stack_a);
		else
			radix_sort(stack_a, &stack_b);
	}
	// print_stacks(*stack_a, stack_b);

	if (stack_a)
		stack_clear(stack_a);
	if (stack_b)
		stack_clear(&stack_b);
}