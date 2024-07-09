/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:40:30 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/22 12:58:06 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	to_zero(unsigned int u, char c)
// {
// 	c = '0' + u;
// 	return (c);
// }

// int	main(void)
// {
// 	char str[] = "Hello, World!";
// 	char *ptr;
// 	printf("Before Address: %p\nBefore String: %s\n", str, str);
// 	ptr = ft_strmapi(str, &to_zero);
// 	printf("After  Address: %p\nAfter  String: %s\n", ptr, ptr);
// 	return (0);
// }