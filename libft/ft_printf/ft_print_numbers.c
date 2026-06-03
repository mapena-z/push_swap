/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 01:21:51 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/30 19:42:14 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int nbr)
{
	ft_putnbr_fd(nbr, 1);
	return (ft_intlen(nbr));
}

int	print_pointer(void *ptr)
{
	int				len;
	unsigned long	new_ptr;

	len = 0;
	new_ptr = (unsigned long)ptr;
	if (new_ptr == 0)
	{
		write(1, "(nil)", 5);
		len = 5;
	}
	else
	{
		write(1, "0x", 2);
		len = 2 + print_hexapointer(new_ptr);
	}
	return (len);
}

int	print_unsigned(unsigned int nbr)
{
	char	c;
	int		len;

	len = ft_unsignedintlen(nbr);
	if (nbr >= 10)
		print_unsigned(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	return (len);
}

int	print_hexalower(unsigned int nbr)
{
	char	word;
	int		len;

	len = 0;
	if (nbr >= 16)
		len = len + print_hexalower(nbr / 16);
	word = ft_hexalowercase(nbr % 16);
	write(1, &word, 1);
	len++;
	return (len);
}

int	print_hexaupper(unsigned int nbr)
{
	char	word;
	int		len;

	len = 0;
	if (nbr >= 16)
		len = len + print_hexaupper(nbr / 16);
	word = ft_hexauppercase(nbr % 16);
	write(1, &word, 1);
	len++;
	return (len);
}
