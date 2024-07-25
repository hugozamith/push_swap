/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:20:15 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/25 11:58:06 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_push_swap **a,
						t_push_swap **b,
						t_push_swap *cheapest)
{
	while (*a != cheapest->target
		&& *b != cheapest)
		rr(a, b, FALSE);
	set_current(*a);
	set_current(*b);
}

static void	reverse_rotate_both(t_push_swap **a,
						t_push_swap **b,
						t_push_swap *cheapest)
{
	while (*a != cheapest->target
		&& *b != cheapest)
		rrr(a, b, FALSE);
	set_current(*a);
	set_current(*b);
}

void	finnish(t_push_swap **stack,
				t_push_swap *top_node,
				char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, FALSE);
			else
				rra(stack, FALSE);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, FALSE);
			else
				rrb(stack, FALSE);
		}
	}
}

static void	move_nodes(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median
		&& cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
		reverse_rotate_both(a, b, cheapest);
	finnish(b, cheapest, 'b');
	finnish(a, cheapest->target, 'a');
	pa(a, b, FALSE);
}

void	push_swap(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*smallest;
	int			len_a;

	len_a = len_of(*a);
	if (len_a == 5)
		handle_small(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, FALSE);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, FALSE);
	else
		while (*a != smallest)
			rra(a, FALSE);
}
