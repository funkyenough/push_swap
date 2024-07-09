/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:01:42 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/10 16:46:41 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_split(char **split, int j)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}

static char	*ft_strndup(const char *src, int n)
{
	char	*dest;
	char	*ptr;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ptr = dest;
	while (*src != 0 && n)
	{
		*ptr = *src;
		ptr++;
		src++;
		n--;
	}
	*ptr = '\0';
	return (dest);
}

static int	str_count(const char *s, char c)
{
	int	wordcount;

	wordcount = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			wordcount++;
		while (*s && (*s != c))
			s++;
	}
	return (wordcount);
}

static char	**split(char const *str, char c, char **result)
{
	int	i;
	int	j;
	int	wordlength;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		wordlength = 0;
		while (str[i + wordlength] && (str[i + wordlength] != c))
			wordlength++;
		if (wordlength)
		{
			result[j] = ft_strndup(&str[i], wordlength);
			if (result[j] == NULL)
				return (free_split(result, j));
			j++;
			i += wordlength;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	result = (char **)malloc((str_count(str, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = split(str, c, result);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "Hello, World, My, Name, Is, Ying.";
// 	char **strs = ft_split(str, ' ');

// 	while (*strs)
// 	{
// 		printf("%s\n", *strs);
// 		strs++;
// 	}
// 	return (0);
// }