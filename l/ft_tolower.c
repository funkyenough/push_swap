/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:16:33 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 12:45:29 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (('A' <= c && c <= 'Z'))
		return (c + ('a' - 'A'));
	else
		return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char a = 'C';
// 	printf("tolower: %c\n", tolower((int)a));
// 	printf("ft_tolo: %c\n", ft_tolower((int)a));
// }