/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:30:31 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/20 17:39:10 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_push_swap **stack)
{
	t_push_swap	*last;
	int				len;

	len = len_of	(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_push_swap **a, int problem)
{
	reverse_rotate(a);
	if (!problem)
		write(1, "rra\n", 4);
}

void	rrb(t_push_swap **b, int problem)
{
	reverse_rotate(b);
	if (!problem)
		write(1, "rrb\n", 4);
}

void	rrr(t_push_swap **a, t_push_swap **b, int problem)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!problem)
		write(1, "rrr\n", 4);
}