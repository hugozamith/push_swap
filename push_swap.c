/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:20:15 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/11 12:01:14 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_init(t_push_swap **a, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (bad_sysntax(argv[i]))
			error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, argv, flag);
		if (found_repetition(*a, (int)nbr))
			error_free(a, argv, flag);
		put_node(a, (int)nbr);
		i++;
	}
	if (flag)
		big_free(argv);
}

int main (int argc, char **argv) 
{
	t_push_swap	*a;
	t_push_swap	*b;

	a = '\0';
	b = '\0';
	if (1 == argc || (2 == argc && !argv[1][0]))
		return(1);
	else if (2 == argc)
		argv = ft_split(argv[1], 32);
	stack_init(&a, argv =1, 2 == argc);
	if (not_sorted(a))
	{
		if (len_of(a) == 2)
			sa(&a, FALSE);
		else if (len_of(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}