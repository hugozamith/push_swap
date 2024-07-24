/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:49 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/22 16:37:22 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_push_swap **head)
{
	int len;

	len = len_of(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = (*head);
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_push_swap	**a, int problem)
{
	swap(a);
	if (!problem)
		write(1, "sa\n", 3);
}

void	sb(t_push_swap **b, int problem)
{
	swap(b);
	if (!problem)
		write(1, "sb\n", 3);
}

void	ss(t_push_swap **a, t_push_swap **b, int problem)
{
	swap(a);
	swap(b);
	if (!problem)
		write(1, "ss\n", 3);
}