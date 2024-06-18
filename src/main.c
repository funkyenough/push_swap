#include "./push_swap.h"

// After sort, the first node of the stack should have the smallest number,
// and the last node should have the largest.

int	main(int argc, char **argv)
{
	int		*intarr;
	int		arr_size;
	t_stack	*stack;

	arr_size = 0;
	intarr = NULL;
	intarr = parse_input(argc, argv, intarr, &arr_size);
	if (has_duplicates(arr_size, intarr))
	{
		// ft_printf("Error: Array has duplicates.\n");
		return (1);
	}
	stack = create_stack(arr_size);
	ft_initialize_stack(intarr, stack);
	sort(&stack);
	stack_clear(&stack);
	free(intarr);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}