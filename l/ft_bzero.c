/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:46:15 by yinhong           #+#    #+#             */
/*   Updated: 2024/04/24 12:11:55 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void) {
//   char str[] = "My Name is Ying.";
//   size_t i;

//   printf("Before bzero:\n");
//   for (i = 0; i < sizeof(str); i++) {
//     printf("%02x ", (unsigned char)str[i]);
//   }
//   printf("\n");
//   ft_bzero(str, 10);
//   printf("After bzero:\n");
//   for (i = 0; i < sizeof(str); i++) {
//     printf("%02x ", (unsigned char)str[i]);
//   }
//   printf("\n");
//   return (0);
// }