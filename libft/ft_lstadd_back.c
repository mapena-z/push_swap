/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:50:15 by mapena-z          #+#    #+#             */
/*   Updated: 2026/05/23 14:59:18 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_lst;

	if (!lst || !new)
		return ;
	new_lst = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (new_lst->next)
		new_lst = new_lst->next;
	new_lst->next = new;
}
