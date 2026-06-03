/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 10:56:30 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/22 03:11:23 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*word;

	i = 0;
	if (!s || !f)
		return (NULL);
	word = malloc(ft_strlen(s) + 1);
	if (!word)
		return (NULL);
	while (s[i] != '\0')
	{
		word[i] = f(i, s[i]);
		i++;
	}
	word[i] = '\0';
	return (word);
}
