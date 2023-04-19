/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:25 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/10 15:02:37 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*s;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = malloc(size);
	if (!s)
		return (0);
	ft_strlcpy(s, s1, size);
	ft_strlcpy(s + ft_strlen(s1), s2, size);
	return (s);
}
