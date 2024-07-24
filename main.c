/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:12:37 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/24 10:05:48 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack_init(&a, argv + 1, 2 == argc);
	if (!stack_sorted(a))
	{
		if (len_of(a) == 2)
			sa(&a, FALSE);
		else if (len_of(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}	
	/*while ((a->value))
	{
		printf("%d \n", a->value);
		a = a->next; 
	}*/
	big_free(&a);
}