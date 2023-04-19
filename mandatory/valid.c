/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:33 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/26 13:35:22 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	wall(char *line, int width)
{
	int	i;

	i = 0;
	if (!line || (line[width - 1] != '\n' && line[width - 1] != '\0'))
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != width - 1)
		return (0);
	return (1);
}

int	valid_line(t_vars	*vars, char	*l, int *p)
{
	int	i;

	i = 0;
	if (l[0] != '1' || l[vars->map.width - 2] != '1')
		return (0);
	while (l[i] != '\n' && l[i])
	{
		if (vars->exit.collec > 1 || (*p) > 1 || (l[vars->map.width - 1]
				!= '\n' && l[vars->map.width - 1]) || (l[i] != '0' && l[i]
				!= 'E' && l[i] != 'P' && l[i] != '1' && l[i] != 'C' && l[i]
				!= 'X' && l[i] != 'Y'))
			return (0);
		if (l[i] == 'C')
			vars->collec.collec++;
		if (l[i] == 'E')
			vars->exit.collec++;
		else if (l[i] == 'P')
			(*p)++;
		i++;
	}
	return (1);
}

int	valid_map(int fd, t_vars *vars)
{
	char	*l;
	int		tmp;
	int		p;

	tmp = 0;
	p = 0;
	l = get_next_line(fd);
	if (!l)
		return (0);
	vars->map.width = ft_strlen(l);
	if (!wall(l, vars->map.width))
		return (free(l), 0);
	while (l)
	{
		if (!valid_line(vars, l, &p))
			return (free(l), 0);
		free(l);
		l = get_next_line(fd);
		vars->map.height++;
		if (wall(l, vars->map.width) && vars->exit.collec && p)
			tmp = vars->map.height;
	}
	if (tmp == vars->map.height - 1 && vars->collec.collec > 0)
		return (1);
	return (0);
}

t_map	map_copy(t_map	*map)
{
	int		y;
	t_map	copy;

	y = 0;
	copy.map = malloc(sizeof(char *) * (map->height + 1));
	if (!copy.map)
		return (copy);
	copy.map[map->height] = 0;
	copy.collec_access = map->collec_access;
	copy.exit_access = map->exit_access;
	copy.player_access = map->player_access;
	copy.width = map->width;
	copy.height = map->height;
	while (map->map[y])
	{
		copy.map[y] = ft_strdup(map->map[y]);
		if (!copy.map[y])
		{
			while (--y > 0)
				free(copy.map[y]);
			return (free(copy.map), copy.map = 0, copy);
		}
		y++;
	}
	return (copy);
}

int	valid_paths(t_map *cpy, int x, int y)
{
	static int	valid_collec;
	static int	valid_exit;

	if (cpy->map[y][x] == '0' || cpy->map[y][x] == 'C' || cpy->map[y][x] == 'P')
	{
		if (cpy->map[y][x] == 'C')
			valid_collec++;
		cpy->map[y][x] = 'V';
	}
	if (cpy->map[y + 1][x] == 'E' || cpy->map[y - 1][x] == 'E'
		|| cpy->map[y][x + 1] == 'E' || cpy->map[y][x - 1] == 'E')
		valid_exit++;
	if (cpy->map[y + 1][x] == '0' || cpy->map[y + 1][x] == 'C')
		valid_paths(cpy, x, y + 1);
	if (cpy->map[y - 1][x] == '0' || cpy->map[y - 1][x] == 'C')
		valid_paths(cpy, x, y - 1);
	if (cpy->map[y][x + 1] == '0' || cpy->map[y][x + 1] == 'C')
		valid_paths(cpy, x + 1, y);
	if (cpy->map[y][x - 1] == '0' || cpy->map[y][x - 1] == 'C')
		valid_paths(cpy, x - 1, y);
	if (valid_exit > 0)
		return (valid_collec);
	return (0);
}
