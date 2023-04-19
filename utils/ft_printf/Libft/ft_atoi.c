/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:49:22 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/16 19:47:39 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;
	int		p;

	i = 0;
	res = 0;
	p = 1;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		p = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (res * p);
		res += nptr[i] - '0';
		i++;
		if (nptr[i] != '\0' && (nptr[i] <= '9' && nptr[i] >= '0'))
			res *= 10;
	}
	return (res * p);
}
