/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:53:55 by ecolin            #+#    #+#             */
/*   Updated: 2022/01/10 13:37:47 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s1 + i) != *((unsigned char *) s2 + i))
			return ((int) *((unsigned char *) s1 + i)
				- *((unsigned char *) s2 + i));
		i++;
	}
	return (0);
}
