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

void	ft_initialize_stack(int *arr, t_stack *stack)
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
		ft_printf("Before sort: ");
	else
		ft_printf("--------------------\nAfter sort: ");
	while (stack)
	{
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	if (state == BEFORE)
		ft_printf("\n--------------------\n");
	else
		ft_printf("\n\nLeaks:\n");
}