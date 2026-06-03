/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:14:58 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/19 11:16:01 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	str1;

	i = 0;
	str = (unsigned char *)s;
	str1 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == str1)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
