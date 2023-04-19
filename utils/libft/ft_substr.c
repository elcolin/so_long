/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:58:13 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/21 00:20:52 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	i = 0;
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	cpy = malloc(len + 1);
	if (!cpy)
		return (0);
	while (i < len && i + start < ft_strlen(s))
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
