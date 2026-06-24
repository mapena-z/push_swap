/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlinaq <carlinaq@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:16:17 by carlinaq          #+#    #+#             */
/*   Updated: 2026/06/24 17:16:24 by carlinaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"
#include "../../../includes/operations.h"

/*
** Number of bits needed to represent the maximum index (n-1).
** For 500 elements: max index = 499 = 0b111110011 → 9 bits.
** Original bits_size(500) also returns 9, but bits_needed(499) is
** semantically correct and avoids an extra pass when n is a power of 2
** (e.g. n=512: bits_size(512)=10 but indices 0..511 only need 9 bits).
*/
static int	bits_needed(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

/*
** Counts elements whose index has [bit] set to 0.
** Called once per pass to enable the skip optimization.
** Cost: O(n) per call, negligible versus the O(n) pass itself.
*/
static int	count_zeros(t_stack *stack, int bit)
{
	t_node	*node;
	int		count;

	node = stack->top;
	count = 0;
	while (node)
	{
		if ((node->index & bit) == 0)
			count++;
		node = node->next;
	}
	return (count);
}

static void	empty_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

/*
** One stable LSD pass for [bit]:
**   index & bit == 0 → pb  (goes to B, comes back on top after empty_b)
**   index & bit == 1 → ra  (cycles to bottom of A)
**
** After n iterations + empty_b:
**   0-bit elements: on top of A, in original relative order  ✓
**   1-bit elements: below, in original relative order        ✓
**
** Note: rr/rrr/ss do NOT apply here. During the pass, B is being
** filled (pb, not rb), so there is no simultaneous useful rotation.
** The only move savings come from skipping passes entirely.
*/
static void	radix_pass(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	i;
	int	n;

	i = 0;
	n = stack_a->size;
	while (i < n)
	{
		if ((stack_a->top->index & bit) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	empty_b(stack_a, stack_b);
}

/*
** LSD Radix Sort — O(n log n) total moves.
**
** Skip optimization:
**   All zeros (zeros == n): n pb's + n pa's = 2n wasted moves → skip.
**   All ones  (zeros == 0): n ra's + 0 pa's =  n wasted moves → skip.
**
** Expected moves for 500 elements (9 bits, random data):
**   Each pass: n (algorithm) + ~n/2 (empty_b) ≈ 750 moves.
**   9 passes × 750 ≈ 6750 total (minus skipped trivial passes).
*/
void	radix(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	bits;
	int	zeros;

	if (!stack_a || !stack_b || stack_a->size <= 1)
		return ;
	bits = bits_needed(stack_a->size - 1);
	bit = 1;
	while (bits-- > 0)
	{
		zeros = count_zeros(stack_a, bit);
		if (zeros > 0 && zeros < stack_a->size)
			radix_pass(stack_a, stack_b, bit);
		bit <<= 1;
	}
}
