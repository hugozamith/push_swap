/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:49 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/25 12:14:57 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*find_last_node(t_push_swap *last_node)
{
	if (NULL == last_node)
		return (NULL);
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	put_node(t_push_swap **stack, int nbr)
{
	t_push_swap	*node;
	t_push_swap	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_push_swap));
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_push_swap	*find_smallest(t_push_swap *stack)
{
	long			smallest;
	t_push_swap		*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_push_swap	*return_cheapest(t_push_swap *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	len_of(t_push_swap *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}
