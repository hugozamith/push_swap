/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:49 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/24 09:56:23 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_push_swap *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

static t_push_swap	*find_highest(t_push_swap *stack)
{
	int			highest;
	t_push_swap	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = -2147483640;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_push_swap **a)
{
	t_push_swap	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, FALSE);
	else if ((*a)->next == highest_node)
		rra(a, FALSE);
	if ((*a)->value > (*a)->next->value)
		sa(a, FALSE);
}

void	handle_small(t_push_swap **a, t_push_swap **b)
{
	while (len_of(*a) > 3)
	{
		init_nodes(*a, *b);
		finnish(a, find_smallest(*a), 'a');
		pb(b, a, FALSE);
	}
}
