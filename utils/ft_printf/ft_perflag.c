/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:00:05 by ecolin            #+#    #+#             */
/*   Updated: 2022/01/06 18:10:36 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	singlechar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstr(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

int	ft_perflag(char c, va_list ptr, int *cnt)
{
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(ptr, int), 1, cnt);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(ptr, unsigned int), 1, cnt);
	else if (c == 's')
		(*cnt) += printstr(va_arg(ptr, char *));
	else if (c == 'x' || c == 'X' || c == 'p')
		(*cnt) += ft_hexaconvert(ptr, c);
	else if (c == 'c')
		(*cnt) += singlechar(va_arg(ptr, int));
	else if (c == '%')
		(*cnt) += singlechar('%');
	else
		return (0);
	return (1);
}
