/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:14:35 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 17:44:18 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char a = '~';
// 	printf("isprint: %d\n", isprint((int)a));
// 	printf("ft_ispr: %d\n", ft_isprint((int)a));
// }