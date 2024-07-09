/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:01:05 by yinhong           #+#    #+#             */
/*   Updated: 2024/07/05 21:48:04 by yinhong          ###   ########.fr       */
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
