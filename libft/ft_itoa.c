/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:25:23 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/24 17:24:28 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*number;
	size_t	len;
	long	new_nb;

	new_nb = n;
	len = ft_len_int(new_nb);
	number = malloc(len + 1);
	if (number == 0)
		return (0);
	number[len] = '\0';
	if (new_nb == 0)
		number[0] = '0';
	if (new_nb < 0)
	{
		number[0] = '-';
		new_nb = -new_nb;
	}
	while (new_nb > 0)
	{
		len--;
		number[len] = new_nb % 10 + '0';
		new_nb = new_nb / 10;
	}
	return (number);
}
