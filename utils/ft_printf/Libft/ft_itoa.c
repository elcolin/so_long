/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:45:58 by ecolin            #+#    #+#             */
/*   Updated: 2022/01/10 13:49:17 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	tab_size(int n)
{
	unsigned int	m;
	int				i;

	i = 0;
	m = ft_abs(n);
	while (m)
	{
		i++;
		m /= 10;
	}
	if (n <= 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	m;
	int				i;
	char			*s;

	i = tab_size(n);
	s = malloc(i + 1);
	if (!s)
		return (0);
	m = ft_abs(n);
	s[i] = '\0';
	while (i - 1 >= 0)
	{
		s[i - 1] = m % 10 + '0';
		m /= 10;
		if (!(i - 1) && n < 0)
			s[0] = '-';
		i--;
	}
	return (s);
}
