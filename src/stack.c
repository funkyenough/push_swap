/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:05 by yinhong           #+#    #+#             */
/*   Updated: 2024/06/18 20:01:06 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int arr_size)
{
	t_stack	*root;
	t_stack	*head;
	t_stack	*new_node;

	root = stack_new(0);
	if (!root)
		return (NULL);
	head = root;
	new_node = NULL;
	while (arr_size-- > 1)
	{
		new_node = stack_new(0);
		if (!new_node)
		{
			stack_clear(&root);
			return (NULL);
		}
		stack_add_tail(&head, new_node);
	}
	return (head);
}

void	initialize_stack(int *arr, t_stack *stack)
{
	while (stack)
	{
		stack->value = *arr;
		stack = stack->next;
		arr++;
	}
}

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
