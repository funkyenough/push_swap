/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:31:14 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/16 18:34:48 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)b;
	while (len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		len--;
	}
	return (b);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*a;
// 	void	*b;

// 	b = NULL;
// 	a = ft_memset(b, 33, 10);
// 	for (int i = 0; i <= 10; i++)
// 	{
// 		printf("Value of a[%d] is: %2X\n", i, a[i]);
// 	}
// }
