/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:00:43 by yinhong           #+#    #+#             */
/*   Updated: 2024/07/09 14:35:57 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

int	*parse_arg_two(char *argv, int *arr_size)
{
	char	**chararr;
	int		*intarr;
	int		i;

	if (!are_digits(argv))
	{
		ft_printf("Error: input includes non-digits\n");
		exit(INCLUDES_NON_DIGITS);
	}
	i = 0;
	*arr_size = str_count(argv, ' ');
	chararr = ft_split(argv, ' ');
	if (!chararr)
		return (NULL);
	intarr = (int *)malloc(sizeof(int) * (*arr_size));
	while (i < *arr_size)
	{
		intarr[i] = ft_atoi(chararr[i]);
		i++;
	}
	return (intarr);
}

int	*parse_all_args(int argc, char **argv)
{
	int	*intarr;
	int	i;

	intarr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!intarr)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (!are_digits(argv[i + 1]))
		{
			ft_printf("Error: input includes non-digits\n");
			free(intarr);
			exit(INCLUDES_NON_DIGITS);
		}
		intarr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (intarr);
}

int	*parse_input(int argc, char **argv, int *intarr, int *arr_size)
{
	if (argc < 2)
	{
		ft_printf("Error: input not found\n");
		exit(INPUT_NOT_FOUND);
	}
	if (argc == 2)
		intarr = parse_arg_two(argv[1], arr_size);
	else
	{
		*arr_size = argc - 1;
		intarr = parse_all_args(argc, argv);
	}
	return (intarr);
}
