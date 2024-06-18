/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:00 by yinhong           #+#    #+#             */
/*   Updated: 2024/06/18 20:01:01 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rrotate(t_stack **a)
{
	t_stack	*second_to_last_node;

	if (!*a || !(*a)->next)
		return ;
	second_to_last_node = *a;
	while (second_to_last_node->next->next != NULL)
		second_to_last_node = second_to_last_node->next;
	stack_add_top(a, stack_new(second_to_last_node->next->value));
	stack_delone(second_to_last_node->next);
	second_to_last_node->next = NULL;
}

void	rra(t_stack **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}