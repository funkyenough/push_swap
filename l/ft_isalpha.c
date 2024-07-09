/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:14:17 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 17:43:28 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("isalpha: %d\n", isalpha((int)'Z'));
// 	printf("ft_isal: %d\n", ft_isalpha((int)'c'));
// }