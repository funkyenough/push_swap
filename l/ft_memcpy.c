/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:15:15 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/22 11:17:12 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n = 15;
// 	const char src[] = "I am the source";
// 	char dst[] = "I am the dstination";

// 	printf("The output is: %s\n", (char *)memcpy(dst, src, n));
// 	return (0);
// }

// int	main(void)
// {
// 	int	src[] = {1, 2, 3, 4, 5};
// 	int	dst[5];

// 	memcpy(dst, src, 5 * sizeof(int));
// 	printf("The output is: ");
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d ", dst[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }

// struct		example
// {
// 	int		a;
// 	float	b;
// 	char	c;
// };

// int	main(void)
// {
// 	struct example src = {1, 2.5, 'c'};
// 	struct example dst;

// 	memcpy(&dst, &src, sizeof(src));

// 	printf("The output is: a = %d, b = %.2f, c = %c\n", dst.a, dst.b, dst.c);

// 	return (0);
// }