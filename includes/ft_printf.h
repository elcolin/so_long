/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elise <elise@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:02:24 by ecolin            #+#    #+#             */
/*   Updated: 2022/07/18 06:06:33 by elise            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include "../utils/libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_hexaconvert(va_list ptr, char c);
int	ft_perflag(char c, va_list ptr, int *cnt);

#endif
