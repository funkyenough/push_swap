/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:03 by yinhong           #+#    #+#             */
/*   Updated: 2024/07/07 10:48:08 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	min;
	int	range;
	int	max_bits;
	int	size;
	int	count;
	int	num;

	max = stack_max_value(*stack_a);
	min = stack_min_value(*stack_a);
	range = max - min;
	max_bits = count_bits((unsigned int)range);
	size = stack_size(*stack_a);
	for (int bit = 0; bit < max_bits; bit++)
	{
		count = 0;
		for (int i = 0; i < size; i++)
		{
			num = (*stack_a)->value - min;
			if ((num >> bit) & 1)
				ra(stack_a);
			else
			{
				pb(stack_a, stack_b);
				count++;
			}
		}
		while (count--)
			pa(stack_a, stack_b);
	}
}

int	count_bits(unsigned int num)
{
	int	bits;

	bits = 0;
	while (num)
	{
		num >>= 1;
		bits++;
	}
	return (bits);
}

int	get_bit(int i, int bit_requested)
{
	return ((i >> bit_requested) & 1);
}
