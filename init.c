/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:34:14 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/22 17:50:27 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *str)
{
	long	nbl;
	int		isneg;
	int		i;
	
	nbl = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
			i++;
	if(str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbl = (nbl * 10) + (str[i] - '0');
		i++;
	}
	return (nbl * isneg);
}

void	stack_init(t_push_swap **a, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (bad_syntax(argv[i]))
			error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, argv, flag);
		if (found_repetition(*a, (int)nbr))
			error_free(a, argv, flag);
		put_node(a, (int)nbr);
		++i;
	}
	if (flag)
		free_matrix(argv);
}