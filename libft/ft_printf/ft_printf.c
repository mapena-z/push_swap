/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 23:22:48 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/30 19:32:28 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_format(char c, va_list args)
{
	if (c == 'c')
		return (print_character(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hexalower(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (print_hexaupper(va_arg(args, unsigned int)));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			i++;
			len = len + set_format(format[i], args);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
