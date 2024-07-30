/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:51:49 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/30 10:03:15 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define LONG_MAX 2147483647
# define LONG_MIN -2147483647

typedef struct s_push_swap
{
	int					value;
	int					current;
	int					cost;
	int					above_median;
	int					cheapest;
	struct s_push_swap	*target;
	struct s_push_swap	*next;
	struct s_push_swap	*prev;
}	t_push_swap;

void		stack_init(t_push_swap **a, char **argv, int flag);
void		push_swap(t_push_swap **a, t_push_swap **b);
void		tiny_sort(t_push_swap **a);
char		**ft_split(char const *s, char c);
void		handle_small(t_push_swap **a, t_push_swap **b);
int			stack_sorted(t_push_swap *stack);
void		finnish(t_push_swap **a, t_push_swap *t, char s);

void		init_nodes(t_push_swap *a, t_push_swap *b);
void		set_cheapest(t_push_swap *b);
void		set_current(t_push_swap *stack);
void		set_price(t_push_swap *a, t_push_swap *b);

size_t		ft_strlcpy(char *dst, const char *src, size_t n);
size_t		ft_strlen(const char *str);
int			found_repetition(t_push_swap *a, int nbr);
int			bad_syntax(char *str_nbr);
void		error_free(t_push_swap **a, char **argv, int flag_argc_2);
void		big_free(t_push_swap **stack);
void		free_matrix(char **argv);

int			len_of(t_push_swap *stack);
t_push_swap	*return_cheapest(t_push_swap *stack);
t_push_swap	*find_smallest(t_push_swap *stack);
void		put_node(t_push_swap **stack, int nbr);
t_push_swap	*find_last_node(t_push_swap *last_node);

void		ss(t_push_swap **a, t_push_swap **b, int problem);
void		sb(t_push_swap **b, int problem);
void		sa(t_push_swap	**a, int problem);
void		ra(t_push_swap **a, int problem);
void		rb(t_push_swap **b, int problem);
void		rr(t_push_swap **a, t_push_swap **b, int problem);
void		rrr(t_push_swap **a, t_push_swap **b, int problem);
void		rrb(t_push_swap **b, int problem);
void		rra(t_push_swap **a, int problem);
void		pa(t_push_swap **a, t_push_swap **b, int problem);
void		pb(t_push_swap **b, t_push_swap **a, int problem);

#endif