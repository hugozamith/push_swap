/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:18:53 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/25 12:38:35 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current(t_push_swap *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (NULL == stack)
		return ;
	centerline = len_of(stack) / 2;
	while (stack)
	{
		stack->current = i;
		if (i <= centerline)
			stack->above_median = TRUE;
		else
			stack->above_median = FALSE;
		stack = stack->next;
		++i;
	}
}

static void	get_target(t_push_swap *a, t_push_swap *b)
{
	t_push_swap		*current_a;
	t_push_swap		*target;
	long			best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_cheapest(t_push_swap *b)
{
	long			best_match_value;
	t_push_swap		*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->cost < best_match_value)
		{
			best_match_value = b->cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = TRUE;
}

void	set_price(t_push_swap *a, t_push_swap *b)
{
	int	al;
	int	bl;

	al = len_of(a);
	bl = len_of(b);
	while (b)
	{
		b->cost = b->current;
		if (!(b->above_median))
			b->cost = bl - (b->current);
		if (b->target->above_median)
			b->cost += b->target->current;
		else
			b->cost += al - (b->target->current);
		b = b->next;
	}
}

void	init_nodes(t_push_swap *a, t_push_swap *b)
{
	set_current(a);
	set_current(b);
	get_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
