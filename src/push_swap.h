/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:03:32 by yinhong           #+#    #+#             */
/*   Updated: 2024/06/18 20:00:53 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <assert.h>
# define TRUE 1
# define FALSE 0

# define BEFORE 0
# define AFTER 1
# define NONE 2

# define INCLUDES_NON_DIGITS 4
# define INPUT_NOT_FOUND 5

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					max_stack_value(t_stack *stack);
int					count_bits(int i);
int					get_bit(int i, int bit_requested);
void				sort(t_stack **stack);

// ------------------------------- STACKUTILS -------------------------------//

void				initialize_stack(int *arr, t_stack *stack);
t_stack				*create_stack(int arr_size);
t_stack				*stack_new(int value);
void				stack_add_tail(t_stack **lst, t_stack *new);
void				stack_add_top(t_stack **lst, t_stack *new);
int					stack_size(t_stack *lst);
t_stack				*stack_get_tail(t_stack *lst);
void				stack_delone(t_stack *lst);
void				stack_clear(t_stack **lst);
void				print_stack(t_stack *stack, int state);
void				print_stacks(t_stack *stack_a, t_stack *stack_b);

// -------------------------------- PARSER -------------------------------- //
int					*parse_arg_two(char *argv, int *arr_size);
int					*parse_all_args(int argc, char **argv);
int					*parse_input(int argc, char **argv, int *intarr,
						int *arr_size);
int					are_digits(char *str);
int					has_duplicates(int arr_size, int *intarr);

// -------------------------------- OPCODES -------------------------------- //
void				sa(t_stack **stack);
void				sb(t_stack **stack);
void				ss(t_stack **a, t_stack **b);

void				ra(t_stack **stack);
void				rb(t_stack **stack);
void				rr(t_stack **a, t_stack **b);

void				rra(t_stack **stack);
void				rrb(t_stack **stack);
void				rrr(t_stack **a, t_stack **b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

#endif