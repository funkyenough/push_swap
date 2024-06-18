#include "./push_swap.h"
#define ARR_SIZE 10

// After sort, the first node of the stack should have the smallest number,
// and the last node should have the largest.

// int	main(int argc, char **argv)
// {
// 	int		*intarr;
// 	int		arr_size;
// 	t_stack	*stack;

// 	arr_size = 0;
// 	intarr = NULL;
// 	intarr = parse_input(argc, argv, intarr, &arr_size);
// 	if (has_duplicates(arr_size, intarr))
// 	{
// 		// ft_printf("Error: Array has duplicates.\n");
// 		return (1);
// 	}
// 	stack = create_stack(arr_size);
// 	initialize_stack(intarr, stack);
// 	sort(&stack);
// 	stack_clear(&stack);
// 	free(intarr);
// 	return (0);
// }

// Test for get_digit
// int	main(void)
// {
// 	int	i;
// 	int	bit_requested;

// 	i = 8;
// 	bit_requested = 0;
// 	ft_printf("Requested Digit is: %d\n", get_bit(i, bit_requested));
// 	assert(get_bit(i, bit_requested) == 0);
// 	bit_requested++;
// 	ft_printf("Requested Digit is: %d\n", get_bit(i, bit_requested));
// 	assert(get_bit(i, bit_requested) == 0);
// 	bit_requested++;
// 	ft_printf("Requested Digit is: %d\n", get_bit(i, bit_requested));
// 	assert(get_bit(i, bit_requested) == 0);
// 	bit_requested++;
// 	ft_printf("Requested Digit is: %d\n", get_bit(i, bit_requested));
// 	assert(get_bit(i, bit_requested) == 1);
// }

// Test for push functions
// int	main(void)
// {
// 	int		arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	t_stack	*stack_a;
// 	t_stack	*stack_b;

// 	stack_b = NULL;
// 	stack_a = create_stack(ARR_SIZE);
// 	initialize_stack(arr, stack_a);
// 	while (stack_a)
// 	{
// 		pb(&stack_a, &stack_b);
// 		print_stacks(stack_a, stack_b);
// 	}
// 	ft_printf("--------------------\n");
// 	while (stack_b)
// 	{
// 		pa(&stack_a, &stack_b);
// 		print_stacks(stack_a, stack_b);
// 	}
// 	stack_clear(&stack_a);
// 	stack_clear(&stack_b);
// }

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}