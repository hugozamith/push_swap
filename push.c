/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:49 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/20 18:33:37 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_push_swap **dest, t_push_swap **src)
{
	t_push_swap	*to_push;
	
	if (NULL == *src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_push_swap **a, t_push_swap **b, int problem)
{
	push(a, b);
	if (!problem)
		write(1, "pa\n", 3);
}

void	pb(t_push_swap **b, t_push_swap **a, int problem)
{
	push(b, a);
	if (!problem)
		write(1, "pb\n", 3);
}