/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:26:13 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/25 12:41:23 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (NULL == dst || NULL == src || !n)
		return (src_len);
	while (*src && --n)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}
