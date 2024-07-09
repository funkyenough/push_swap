/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:14 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/19 17:03:06 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	char	*ptr;

	src_len = ft_strlen(src);
	ptr = dst;
	if (dstsize != 0)
	{
		while (*src && --dstsize)
			*ptr++ = *src++;
		*ptr = '\0';
	}
	return (src_len);
}
