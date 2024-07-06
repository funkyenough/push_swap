/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:03 by yinhong           #+#    #+#             */
/*   Updated: 2024/07/06 12:02:16 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max;
	int		max_bits;
	int		current_bit;
	t_stack	*first;

	first = NULL;
	max = stack_max_value(*stack_a);
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
