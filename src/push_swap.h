#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void del(void *content);
t_list *create_stack(int arr_size);
void ft_initialize_stack(int *arr, t_list *stack);
void print_stack(t_list *stack);

#endif