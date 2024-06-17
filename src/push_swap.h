#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# define TRUE 1
# define FALSE 0

# define INCLUDES_NON_DIGITS 4
# define INPUT_NOT_FOUND 5

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*create_stack(int arr_size);
void				ft_initialize_stack(int arr_size, int *arr, t_stack *stack);
void				print_stack(t_stack *stack);
void				sort(t_stack *stack_a);
void				sa(t_stack *a);
void				ra(t_stack **a);
t_stack				*stack_last(t_stack *lst);
void				stack_add_front(t_stack **lst, t_stack *new);
void				stack_add_back(t_stack **lst, t_stack *new);
void				stack_delone(t_stack *lst);
void				stack_clear(t_stack **lst);
int					stack_size(t_stack *lst);
t_stack				*stack_new(int value);

int					are_digits(char *str);
int					has_duplicates(int arr_size, int *intarr);
int					*parse_arg_two(char *argv, int *arr_size);
int					*parse_all_args(int argc, char **argv);
int					*parse_input(int argc, char **argv, int *intarr,
						int *arr_size);
#endif