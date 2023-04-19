/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:30:15 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/25 18:46:44 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	freeenemies(t_vars *vars, t_enemy **enemy)
{
	int		i;
	t_enemy	*tmp;
	int		size;

	size = vars->map.num_enemies;
	i = 0;
	while (i++ < size)
	{
		tmp = (*enemy)->next;
		free((*enemy));
		(*enemy) = tmp;
	}
}

void	freeanim(t_vars *vars, t_playimg **anim)
{
	int			size;
	int			i;
	t_playimg	*tmp;

	i = 0;
	if (!(*anim))
		return ;
	size = (*anim)->num;
	while (i < size)
	{
		tmp = (*anim);
		mlx_destroy_image(vars->mlx, tmp->data.img);
		(*anim) = tmp->next;
		free((tmp));
		i++;
	}
}

void	destroy(t_vars *vars)
{
	usleep(100000);
	mlx_destroy_window(vars->mlx, vars->win);
	freemap(&vars->map);
	freeenemies(vars, &vars->enemy);
	freeanim(vars, &vars->map.aanim_enemy);
	freeanim(vars, &vars->map.danim_enemy);
	freeanim(vars, &vars->map.aanim_knight);
	freeanim(vars, &vars->map.danim_knight);
	freeanim(vars, &vars->map.anim_explo);
	mlx_destroy_image(vars->mlx, vars->map.exit.img);
	mlx_destroy_image(vars->mlx, vars->map.collec.img);
	mlx_destroy_image(vars->mlx, vars->map.wall.img);
	mlx_destroy_image(vars->mlx, vars->map.floor.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

int	freemap(t_map *map)
{
	int	y;

	y = 0;
	if (!map->map)
		return (0);
	while (y < map->height)
	{
		if (map->map[y])
			free(map->map[y]);
		y++;
	}
	free(map->map);
	return (0);
}
