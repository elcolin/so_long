/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:58:40 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/26 13:41:15 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_vars(t_vars *vars)
{
	t_map	cpy;
	int		path;

	vars->player = find_create_player(vars->map.map);
	vars->map.collec_access = &vars->collec;
	vars->map.exit_access = &vars->exit;
	vars->map.player_access = &vars->player;
	vars->player.orient = 'd';
	vars->exit.orient = 0;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	create_assets(&vars->map, vars);
	vars->win = mlx_new_window(vars->mlx, vars->map.width
			* vars->map.floor.img_width, vars->map.height
			* vars->map.floor.img_height, "so_long");
	vars->map.num_enemies = find_enemies(vars);
	cpy = map_copy(&vars->map);
	if (!cpy.map)
		return (destroy(vars), 0);
	path = valid_paths(&cpy, vars->player.x, vars->player.y);
	freemap(&cpy);
	if (!path || path < vars->collec.collec)
		ft_printf("Warning, no valid path found!\n");
	return (1);
}

t_playimg	*create_anim(char *name, int num, t_vars *vars, char *ext)
{
	int			i;
	t_playimg	*anim;
	t_playimg	*index;
	char		*tmp;
	char		*tmp_ext;

	i = 0;
	tmp = ft_strjoin(name, ext);
	anim = new_playimg(vars, tmp, i, num);
	index = anim;
	free(tmp);
	while (i < num - 1)
	{
		tmp = ft_itoa(i);
		tmp_ext = ft_strjoin(tmp, ext);
		free(tmp);
		tmp = ft_strjoin(name, tmp_ext);
		index->next = new_playimg(vars, tmp, i + 1, num);
		free(tmp_ext);
		free(tmp);
		index = index->next;
		i++;
	}
	index->next = anim;
	return (anim);
}

void	create_assets(t_map	*map, t_vars *vars)
{
	map->floor.img = mlx_xpm_file_to_image(vars->mlx, "assets/floor32.xpm",
			&map->floor.img_width, &map->floor.img_height);
	map->wall.img = mlx_xpm_file_to_image(vars->mlx, "assets/wall32.xpm",
			&map->wall.img_width, &map->wall.img_height);
	map->exit.img = mlx_xpm_file_to_image(vars->mlx, "assets/nextlevel32.xpm",
			&map->exit.img_width, &map->exit.img_height);
	map->collec.img = mlx_xpm_file_to_image(vars->mlx, "assets/key32.xpm",
			&map->collec.img_width, &map->collec.img_height);
	map->floor.addr = mlx_get_data_addr(map->floor.img,
			&map->floor.bits_per_pixel, &map->floor.line_length,
			&map->floor.endian);
	vars->map.aanim_knight = create_anim("assets/knight/Aknight32-",
			5, vars, ".xpm");
	vars->map.danim_knight = create_anim("assets/knight/Dknight32-",
			5, vars, ".xpm");
	vars->map.anim_explo = create_anim("assets/next/explosion_anim_f",
			6, vars, ".xpm");
	vars->map.danim_enemy = create_anim("assets/enemies/goblin_idle_anim32_f",
			5, vars, ".xpm");
	vars->map.aanim_enemy = create_anim("assets/enemies/Agoblin_idle_anim32_f",
			5, vars, ".xpm");
	no_transparency(&map->collec, &map->floor);
	no_transparency(&map->exit, &map->wall);
	no_transparency(&map->wall, &map->floor);
}

t_playimg	*new_playimg(t_vars *vars, char *name, int id, int num)
{
	t_playimg	*anim;

	anim = malloc(sizeof(t_playimg));
	if (!anim)
		return (0);
	anim->data.img = mlx_xpm_file_to_image(vars->mlx, name,
			&anim->data.img_width, &anim->data.img_height);
	no_transparency(&anim->data, &vars->map.floor);
	anim->next = 0;
	anim->id = id;
	anim->num = num;
	return (anim);
}
