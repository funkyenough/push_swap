/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:42:09 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/22 11:03:15 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	helper(int *len, int *sign, long *num)
{
	*len = 0;
	*sign = 1;
	if (*num < 0)
	{
		*sign *= -1;
		(*len)++;
	}
	while (*num)
	{
		(*len)++;
		(*num) /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	helper(&len, &sign, &num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	num = n;
	num *= sign;
	while (len)
	{
		str[--len] = num % 10 + '0';
		num /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

// int	main(void)
// {
// 	int i = -2147483648;
// 	printf("ft_itoa: %s\n", ft_itoa(i));
// 	return (0);
// }