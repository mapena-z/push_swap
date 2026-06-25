/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapena-z <mapena-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:18:07 by mapena-z          #+#    #+#             */
/*   Updated: 2026/06/25 11:18:08 by mapena-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../includes/push_swap.h"

//void	stack_print(t_stack *stack)
//{
//	t_node *node;

//	if (!stack)
//		return ;
//	ft_putstr_fd("Stack ", 1);
//	ft_putchar_fd(stack->name, 1);
//	ft_putstr_fd(" (size: ", 1);
//	ft_putnbr_fd(stack->size, 1);
//	ft_putstr_fd(")\n", 1);
//	node = stack->top;
//	while (node)
//	{
//		ft_putnbr_fd(node->value, 1);
//		ft_putstr_fd(" (idx:", 1);
//		ft_putnbr_fd(node->index, 1);
//		ft_putstr_fd(")\n", 1);
//		node = node->next;
//	}
//}

//void	stack_print_both(t_stack *a, t_stack *b)
//{
//	ft_putstr_fd("--- STACK A ---\n", 1);
//	stack_print(a);
//	ft_putstr_fd("\n--- STACK B ---\n", 1);
//	stack_print(b);
//}

//void    stack_print_index(t_stack *stack)
//{
//    t_node  *current;

//    if (!stack)
//    {
//        ft_printf("Stack no inicializado (NULL)\n");
//        return ;
//    }
//    ft_printf("--- Stack %c (Size: %d) ---\n", stack->name, stack->size);
//    if (!stack->top)
//    {
//        ft_printf("[ Vacio ]\n");
//        ft_printf("-----------------------\n\n");
//        return ;
//    }
//    current = stack->top;
//    while (current)
//    {
//        // Imprime el valor real y su índice alineados
//        ft_printf("Valor: %11d  |  Index: %d\n", 
//			current->value, current->index);
//        current = current->next;
//    }
//    ft_printf("-----------------------\n\n");
//}