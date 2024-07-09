/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:15:11 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/10 12:15:12 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char s1[] = "I am a Btring";
// 	const char s2[] = "I am a String";
// 	int n = 14;

// 	printf("ft_cmp: %d\n", ft_memcmp(s1, s2, n));
// 	printf("memcmp: %d\n", memcmp(s1, s2, n));

// 	return (0);
// }