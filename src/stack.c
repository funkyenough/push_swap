#include "push_swap.h"

t_list *create_stack(int arr_size)
{
	t_list *root;
	t_list *head;
	t_list *new_node;

	root = ft_lstnew((int *)malloc(sizeof(int)));
	if (!root->content)
		return NULL;
	head = root;
	new_node = NULL;
	while (arr_size-- > 1)
	{
		new_node = ft_lstnew((int *)malloc(sizeof(int)));
		if (!new_node->content)
		{
			ft_lstclear(&root, del);
			return NULL;
		}
		ft_lstadd_front(&head, new_node);
		head = new_node;
	}
	return head;
}
// The first element is at the top of the stack,
// meaning that the last node has the first element of the array
void ft_initialize_stack(int arr_size, int *arr, t_list *stack)
{
	arr += (arr_size - 1);
	while(stack)
	{
		*((int*)stack->content) = *arr;
		stack = stack->next;
		arr--;
	}
}

void print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n", *((int *)stack->content));
		stack = stack->next;
	}
}