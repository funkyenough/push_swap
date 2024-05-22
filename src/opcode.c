#include <stdio.h>
#include "push_swap.h"

void swap(t_list *a, t_list *b)
{
    void *c;

    if (!a || !b)
        return;
    c = a->content;
    a->content = b->content;
    b->content = c;
}

void rotate(t_list **a)
{
    t_list *new_node;

    if (!*a || !(*a)->next)
        return;
    new_node = *a;
    *a = (*a)->next;
    ft_lstadd_back(a, new_node);
}

void rrotate(t_list **a)
{
    t_list *new_node;

    if (!*a || !(*a)->next)
        return;
    new_node = ft_lstlast(*a);
    ft_lstadd_front(a, new_node);
    ft_lstdelone(new_node, del);
}

void sa(t_list *a)
{
    swap(a, a->next);
}

void sb(t_list *b)
{
    swap(b, b->next);
}

void ss(t_list *a, t_list *b)
{
    sa(a);
    sb(b);
}

void pa(t_list **a, t_list **b)
{
    t_list *node;

    if (*b)
    {
        node = ft_lstlast(*b);
        ft_lstadd_front(a, node);
        ft_lstdelone(node, del);
    }
}

void pb(t_list **a, t_list **b)
{
    t_list *node;

    if (*a)
    {
        node = ft_lstlast(*a);
        ft_lstadd_front(b, node);
        ft_lstdelone(node, del);
    }
}

void ra(t_list **a)
{
    rotate(a);
}

void rb(t_list **b)
{
    rotate(b);
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

void rra(t_list **a)
{
    rrotate(a);
}

void rrb(t_list **b)
{
    rrotate(b);
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}