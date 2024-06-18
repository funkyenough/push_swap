#include "./push_swap.h"

void	stack_add_tail(t_stack **lst, t_stack *new)
{
	if (*lst == NULL)
		*lst = new;
	else if (lst != NULL && new != NULL)
		stack_get_tail(*lst)->next = new;
}

void	stack_add_top(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	stack_delone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

t_stack	*stack_get_tail(t_stack *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	stack_clear(t_stack **lst)
{
	t_stack	*next_node;

	if (lst)
	{
		while (*lst)
		{
			next_node = (*lst)->next;
			stack_delone(*lst);
			*lst = next_node;
		}
	}
}

int	stack_size(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_stack	*stack_new(int value)
{
	t_stack *node;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}