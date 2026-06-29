/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 15:01:47 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/29 11:56:30 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*temp;

	if (!lst || !del)
		return ;
	new_lst = *lst;
	while (new_lst)
	{
		temp = new_lst;
		new_lst = new_lst->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
