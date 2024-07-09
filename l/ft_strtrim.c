/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:28:11 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/25 12:45:48 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*ptr;
	int		start;
	int		end;

	if (!s1 || !set)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isset(s1[start], set))
		start++;
	while (ft_isset(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = (char *)malloc(((end + 1) - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ptr = str;
	while (start <= end)
		*ptr++ = s1[start++];
	*ptr = '\0';
	return (str);
}

// int main(void)
// {
// 	char const *s = "  \t \t \n   \n\n\n\t";
// 	printf("ft_strtrim: %s\n", ft_strtrim(s));

// 	return (0);
// }