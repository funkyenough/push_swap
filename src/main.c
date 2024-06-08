#include "push_swap.h"

void del(void *content)
{
	free(content);
}

int	str_count(const char *s, char c)
{
	int	wordcount;

	wordcount = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			wordcount++;
		while (*s && (*s != c))
			s++;
	}
	return (wordcount);
}

int *parse_arg_two(char *argv, int *arr_size)
{
	char **chararr;
	int *intarr;
	int i;

	i = 0;
	*arr_size = str_count(argv, ' ');
	chararr = ft_split(argv, ' ');
	if (!chararr)
		return NULL;
	intarr = (int *)malloc(sizeof(int) * (*arr_size));

	while (i < *arr_size)
	{
		intarr[i] = ft_atoi(chararr[i]);
		i++;
	}
	return intarr;
}

int *parse_all_args(int argc, char **argv)
{
	int *intarr;
	int i;

	intarr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!intarr)
		return NULL;
	i = 0;
	while (i < argc - 1)
	{
		intarr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return intarr;
}

int	main(int argc, char **argv)
{
	int *intarr;
	int arr_size;
	t_list *stack;

	arr_size = 0;
	intarr = NULL;
	if (argc < 2)
	{
		ft_printf("Error");
		return 1;
	}
	if (argc == 2)
		intarr = parse_arg_two(argv[1], &arr_size);
	else
	{
		arr_size = argc - 1;
		intarr = parse_all_args(argc, argv);
	}

	// for (int i = 0; i < arr_size; i++)
	// 	ft_printf("%d\n", intarr[i]);

	stack = create_stack(arr_size);
	ft_initialize_stack(intarr, stack);
	print_stack(stack);
	return 0;
}