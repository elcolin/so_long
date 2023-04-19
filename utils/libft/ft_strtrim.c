/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:07:33 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/20 21:44:35 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	edge(char const *s1, char const *set, size_t i, size_t size)
{
	size_t			j;
	int long long	ed;

	j = 0;
	ed = -1;
	while (i != size && ed == -1)
	{
		j = 0;
		if (set[j] != s1[i])
		{
			while (set[j] != '\0' && set[j] != s1[i])
				j++;
			if (set[j] == '\0')
				ed = i;
		}
		if (size == ft_strlen(s1) + 1)
			i++;
		else
			i--;
	}
	return (ed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	deb;
	size_t	fin;
	char	*cpy;

	cpy = NULL;
	deb = edge(s1, set, 0, ft_strlen(s1) + 1);
	fin = edge(s1, set, ft_strlen(s1) - 1, -1);
	if (deb == ft_strlen(s1))
	{
		cpy = malloc(1);
		*cpy = '\0';
		return (cpy);
	}
	cpy = malloc(fin - deb + 2);
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, &s1[deb], fin - deb + 2);
	return (cpy);
}
