/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:14:31 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 17:43:59 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char c = '8';
// 	printf("isdigit: %d\n", isdigit((int)c));
// 	printf("ft_isdi: %d\n", ft_isdigit((int)c));
// }