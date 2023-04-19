/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:26 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/26 13:44:11 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_enemy	*new_enemy(int x, int y, int id, char axis)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		return (0);
	enemy->pos.x = x;
	enemy->pos.y = y;
	enemy->axis = axis;
	enemy->id = id;
	enemy->next = 0;
	if (axis == 'X')
		enemy->pos.orient = 'd';
	else
		enemy->pos.orient = 's';
	return (enemy);
}

void	find_enemies2(t_vars *vars, int y, t_enemy **index)
{
	int	x;

	x = 0;
	while (x < vars->map.width && vars->map.map[y])
	{
		if ((vars->map.map[y][x] == 'X'
			|| vars->map.map[y][x] == 'Y') && !vars->map.num_enemies)
		{
			vars->enemy = new_enemy(x, y,
					vars->map.num_enemies++, vars->map.map[y][x]);
			(*index) = vars->enemy;
		}
		else if (vars->map.map[y][x] == 'X' || vars->map.map[y][x] == 'Y')
		{
			(*index)->next = new_enemy(x, y,
					vars->map.num_enemies++, vars->map.map[y][x]);
			(*index) = (*index)->next;
		}
		x++;
	}
}

int	find_enemies(t_vars *vars)
{
	int		y;
	t_enemy	*index;

	y = 0;
	vars->map.num_enemies = 0;
	index = 0;
	while (y < vars->map.height && vars->map.map[y])
	{
		find_enemies2(vars, y, &index);
		y++;
	}
	if (vars->map.num_enemies)
		index->next = vars->enemy;
	return (vars->map.num_enemies);
}

t_player	find_create_player(char	**map)
{
	t_player	player;
	int			i;
	int			j;

	i = 0;
	j = 0;
	player.collec = 0;
	while (!ft_strchr(map[i], 'P'))
		i++;
	player.y = i;
	while (map[player.y][j] != 'P')
		j++;
	player.x = j;
	return (player);
}

int	create_map(int fd, t_map *map)
{
	char	*l;
	int		i;

	i = 0;
	l = get_next_line(fd);
	map->width = ft_strlen(l);
	map->map = malloc((map->height + 1) * sizeof(char *));
	if (!map->map)
		return (0);
	map->map[map->height] = 0;
	while (l)
	{
		map->map[i] = malloc(map->width);
		if (!map->map[i])
		{
			while (i--)
				return (free(map->map[i]), 0);
		}
		ft_strlcpy(map->map[i++], l, map->width);
		free(l);
		l = get_next_line(fd);
	}
	map->width--;
	return (1);
}
