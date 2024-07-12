/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hteixeir <hteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:09:15 by hteixeir          #+#    #+#             */
/*   Updated: 2024/07/09 11:32:11 by hteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_slicecount(char const *pao, char n)
{
	int		dentro;
	size_t	fatias;

	fatias = 0;
	while (*pao)
	{
		dentro = 1;
		while (*pao == n && *pao)
			pao++;
		while (*pao != n && *pao)
		{
			if (dentro)
			{
				fatias++;
				dentro = 0;
			}
			pao++;
		}
	}
	return (fatias);
}

int	ft_safe_malloc(char **ret, int x, int i)
{
	int		y;

	y = 0;
	ret[x] = malloc(i * sizeof(char));
	if (ret[x] == NULL)
	{
		while (y < x)
			free(ret[y++]);
		free(ret);
		return (1);
	}
	return (0);
}

int	ft_fill(char **ret, char const *s, char c)
{
	int		palavra;
	size_t	len;

	palavra = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		if (len)
		{
			if (ft_safe_malloc(ret, palavra, len + 1))
				return (0);
			ft_strlcpy(ret[palavra], s - len, len + 1);
		}
		palavra++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	palavras;
	char	**ret;

	if (!(s))
		return (NULL);
	palavras = 0;
	palavras = (ft_slicecount(s, c));
	ret = malloc((palavras + 1) * sizeof(char *));
	if (!(ret))
		return (NULL);
	ret[palavras] = (NULL);
	if (!(ft_fill(ret, s, c)))
		return (NULL);
	return (ret);
}