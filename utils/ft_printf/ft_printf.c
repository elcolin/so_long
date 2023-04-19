/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:08:18 by ecolin            #+#    #+#             */
/*   Updated: 2022/01/10 13:35:26 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	size_t	i;	
	int		j;

	va_start(ptr, format);
	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i++] == '%' && ft_perflag(format[i], ptr, &j))
			i++;
		else
		{
			ft_putchar_fd(format[i - 1], 1);
			j++;
		}
	}
	va_end(ptr);
	return (j);
}
