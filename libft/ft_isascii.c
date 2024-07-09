/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:14:22 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 17:43:52 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char c = 'C';
// 	printf("isascii: %d\n", isascii((int)c));
// 	printf("ft_isas: %d\n", ft_isascii((int)c));
// }