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
		stack_add_front(&head, new_node);
		head = new_node;
	}
	return (head);
}
// The first element is at the top of the stack,
// meaning that the last node has the first element of the array
void	ft_initialize_stack(int arr_size, int *arr, t_stack *stack)
{
	arr += (arr_size - 1);
	while (stack)
	{
		stack->value = *arr;
		stack = stack->next;
		arr--;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}