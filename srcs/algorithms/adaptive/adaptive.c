/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/06/28 11:18:08 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/algorithms.h"

void	adaptive_sort(t_stack *stack_a, t_stack *stack_b)
{
	double	disorder;

	if (!stack_a || !stack_b)
		return ;
	disorder = compute_disorder(stack_a);
	if (disorder < 0.2)
		turk_sort(stack_a, stack_b);
	else if (disorder < 0.5)
		chunk_sort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
