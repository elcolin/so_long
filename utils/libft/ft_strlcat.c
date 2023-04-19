/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:55:57 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/07 15:56:07 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (i + j < size - 1)
	{
		dst[i + j] = src[j];
		if (src[j] == '\0')
			return (i + j);
		j++;
	}
	dst[i + j] = '\0';
	if (i > size)
		return (size + ft_strlen(src));
	return (i + ft_strlen(src));
}
