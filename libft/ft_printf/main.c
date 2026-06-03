/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 00:27:21 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/30 00:52:28 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf(" %d\n", ft_printf("hola mundo que tal %c %s", 'a', "esta mi gente"));
	printf(" %d\n", printf("hola mundo que tal %c %s", 'a', "esta mi gente"));
}
