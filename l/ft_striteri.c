/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:50:50 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/22 13:17:22 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	to_zero(unsigned int u, char *c)
// {
// 	*c = '0' + u;
// }

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	printf("Before: %s\n", str);
// 	ft_striteri(str, &to_zero);
// 	printf("after: %s\n", str);
// 	return (0);
// }