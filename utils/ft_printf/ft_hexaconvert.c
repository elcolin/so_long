/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaconvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:30 by ecolin            #+#    #+#             */
/*   Updated: 2022/01/10 13:47:54 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <limits.h>

int	itx(unsigned long int x, int *hex)
{
	int	i;

	i = 0;
	if (!x)
		hex[i++] = 0;
	while (x && i < 20)
	{
		hex[i++] = x % 16;
		x = (x - (x % 16)) / 16;
	}
	return (i);
}

int	printhex(int *hex, int x, char *base)
{
	int	i;

	i = x;
	while (--x >= 0)
		ft_putchar_fd(base[hex[x]], 1);
	return (i);
}

int	ft_hexaconvert(va_list ptr, char c)
{
	int					hex[20];
	unsigned int long	p;

	p = 0;
	if (c == 'x')
		return (printhex(hex, itx(va_arg(ptr, unsigned int),
					hex), "0123456789abcdef"));
	else if (c == 'X')
		return (printhex(hex, itx(va_arg(ptr, unsigned int),
					hex), "0123456789ABCDEF"));
	else if (c == 'p')
	{
		p = va_arg(ptr, unsigned long int);
		ft_putstr_fd("0x", 1);
		return (printhex(hex, itx(p, hex), "0123456789abcdef") + 2);
	}
	return (0);
}
