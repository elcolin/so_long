/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:06:11 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/20 23:53:37 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (0);
	while (i < ft_strlen(s))
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[ft_strlen(s)] = '\0';
	return (dst);
}
