/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:22 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/22 11:44:12 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((!s1 || !s2) && n == 0)
		return (0);
	while ((*s1 || *s2) && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// char s1[] = "Hello, World!";
// 	// char s2[] = "";
// 	// int n = 13;

// 	// printf("strcmp: %d\n", strncmp(s1, s2, n));
// 	// printf("ft_str: %d\n", ft_strncmp(s1, s2, n));
// 	// printf("strcmp: %d\n", strncmp(NULL, "Hello", 0));
// 	// printf("ft_str: %d\n", ft_strncmp(NULL, "Hello", 0));
// 	printf("ft_str: %d\n", strncmp((void *)0, "nope", 3));
// 	printf("ft_str: %d\n", ft_strncmp((void *)0, "nope", 3));
// }