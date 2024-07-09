/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:27 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/23 18:53:02 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*start;

	start = NULL;
	while (*s)
	{
		if (*s == (char)c)
			start = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)start);
}

// #include <stdio.h>

// int	main(void)
// {
// 	// 	char str[] = "\0";
// 	// 	int c = (int)'a';

// 	printf("ft_strr: %p\n", ft_strrchr("teste", 'e'));
// 	printf("strrchr: %p\n", strrchr("teste", 'e'));

// 	// 	printf("ft_strr: %p\n", ft_strrchr(str, c));
// }