/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:20:38 by ecolin            #+#    #+#             */
/*   Updated: 2021/12/28 16:37:33 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	*ft_putnbr_fd(long int n, int fd, int *c)
{
	long int	m;

	m = n;
	if (m < 0)
		m *= -1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		(*c)++;
	}
	if (m >= 10)
		ft_putnbr_fd(m / 10, fd, c);
	ft_putchar_fd(m % 10 + '0', fd);
	(*c)++;
	return (c);
}
