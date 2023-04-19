/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:05 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/25 18:39:47 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_element(t_data *elem, t_vars *vars, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, elem->img,
		x * elem->img_width, y * elem->img_height);
}

int	not_floor(t_vars *vars, int x, int y, char c)
{
	if (((vars->map.map[y][x] == 'X' || vars->map.map[y][x] == 'Y') && !c)
			|| c == 'X' || c == 'Y')
		return (display_element(&vars->map.danim_enemy->data, vars, x, y), 0);
	if ((vars->map.map[y][x] == '0' && !c) || c == '0')
		return (display_element(&vars->map.floor, vars, x, y), 0);
	if ((vars->map.map[y][x] == '1' && !c) || c == '1')
		return (display_element(&vars->map.wall, vars, x, y), 0);
	if ((vars->map.map[y][x] == 'P' && !c) || c == 'd')
		return (display_element(&vars->map.danim_knight->data, vars, x, y), 0);
	if ((vars->map.map[y][x] == 'P' && !c) || c == 'a')
		return (display_element(&vars->map.aanim_knight->data, vars, x, y), 0);
	if ((vars->map.map[y][x] == 'C' && !c) || c == 'C')
		return (display_element(&vars->map.collec, vars, x, y), 0);
	if ((vars->map.map[y][x] == 'E' && !c) || c == 'E')
	{
		display_element(&vars->map.wall, vars, x, y);
		vars->exit.x = x;
		vars->exit.y = y;
		if (vars->player.collec == vars->collec.collec && vars->collec.collec)
			return (display_element(&vars->map.exit, vars, x, y), 0);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, long int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	no_transparency(t_data	*b_img, t_data	*r_img)
{
	int			x;
	int			y;
	int			offset;
	char		*l;
	long int	*k;

	y = 0;
	x = 0;
	b_img->addr = mlx_get_data_addr(b_img->img, &b_img->bits_per_pixel,
			&b_img->line_length, &b_img->endian);
	offset = (y * b_img->line_length + x * (b_img->bits_per_pixel / 8));
	while (y < b_img->img_height)
	{
		x = 0;
		while (x < b_img->img_width)
		{
			offset = (y * b_img->line_length + x * (b_img->bits_per_pixel / 8));
			l = b_img->addr + offset + 3;
			k = (void *) r_img->addr + offset;
			if (*l)
				my_mlx_pixel_put(b_img, x, y, *k);
			x++;
		}
		y++;
	}
}

void	display_map(t_vars	*vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			not_floor(vars, x, y, '0');
			if (vars->map.map[y][x] != '0')
				not_floor(vars, x, y, 0);
			x++;
		}
		y++;
	}
}
