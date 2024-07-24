/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:07:07 by utente            #+#    #+#             */
/*   Updated: 2024/07/20 17:39:39 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_push_swap **stack)
{
	t_push_swap	*last_node;
	int				len;

	len = len_of(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}	

void	ra(t_push_swap **a, int problem)
{
	rotate(a);
	if (!problem)
		write(1, "ra\n", 3);
}

void	rb(t_push_swap **b, int problem)
{
	rotate(b);
	if (!problem)
		write(1, "rb\n", 3);
}

void	rr(t_push_swap **a, t_push_swap **b, int problem)
{
	rotate(a);
	rotate(b);
	if (!problem)
		write(1, "rr\n", 3);
}