/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:04:15 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/25 18:27:08 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	movement(t_vars *vars, int y, int x, t_player *player)
{
	if (vars->map.map[player->y + y][player->x + x] == 'C'
		&& player->collec + 1 == vars->collec.collec)
		not_floor(vars, vars->exit.x, vars->exit.y, 0);
	if (player->collec == vars->collec.collec
		&& vars->map.map[player->y + y][player->x + x] == 'E')
		destroy(vars);
	else if (vars->map.map[player->y + y][player->x + x] == '1'
		|| vars->map.map[player->y + y][player->x + x] == 'E')
		return (-1);
	else if (vars->map.map[player->y + y][player->x + x] == 'C')
		player->collec += 1;
	vars->map.map[player->y][player->x] = '0';
	player->y += y;
	player->x += x;
	vars->map.map[player->y][player->x] = 'P';
	return (0);
}

int	movement_op(t_vars *vars, int x, int y, char c)
{
	t_player	tmp;

	tmp.x = vars->enemy->pos.x;
	tmp.y = vars->enemy->pos.y;
	if (vars->enemy->pos.orient == c
		&& vars->map.map[tmp.y + y][tmp.x + x] == '0')
	{
		vars->enemy->pos.x += x;
		vars->enemy->pos.y += y;
		vars->map.map[tmp.y][tmp.x] = '0';
		vars->map.map[vars->enemy->pos.y][vars->enemy->pos.x] = 'X';
		not_floor(vars, tmp.x, tmp.y, 0);
		not_floor(vars, vars->enemy->pos.x, vars->enemy->pos.y, 0);
		return (1);
	}
	return (0);
}

void	enemy_movement(t_vars *vars, t_enemy **enemy)
{
	t_player	tmp;

	tmp.x = (*enemy)->pos.x;
	tmp.y = (*enemy)->pos.y;
	if (movement_op(vars, 1, 0, 'd'))
		return ;
	else if ((*enemy)->pos.orient == 'd'
		&& vars->map.map[tmp.y][(*enemy)->pos.x + 1] != '0')
		(*enemy)->pos.orient = 'a';
	if (movement_op(vars, -1, 0, 'a'))
		return ;
	else if ((*enemy)->pos.orient == 'a'
		&& vars->map.map[tmp.y][(*enemy)->pos.x - 1] != '0')
		(*enemy)->pos.orient = 'd';
	if (movement_op(vars, 0, 1, 's'))
		return ;
	else if ((*enemy)->pos.orient == 's'
		&& vars->map.map[tmp.y + 1][tmp.x] != '0')
		(*enemy)->pos.orient = 'w';
	if (movement_op(vars, 0, -1, 'w'))
		return ;
	else if ((*enemy)->pos.orient == 'w'
		&& vars->map.map[tmp.y - 1][tmp.x] != '0')
		(*enemy)->pos.orient = 's';
}

int	surroundings(t_vars *vars, int x, int y, char c)
{
	if (vars->map.map[y - 1][x] == c || vars->map.map[y][x - 1] == c
		|| vars->map.map[y][x + 1] == c || vars->map.map[y + 1][x] == c)
		return (1);
	return (0);
}

void	enemy_round(t_vars *vars)
{
	static int	i;
	int			j;

	j = 0;
	while (j < vars->map.num_enemies)
	{
		if ((i >= 10 * vars->map.num_enemies)
			&& (i <= 14 * vars->map.num_enemies))
			enemy_movement(vars, &vars->enemy);
		if (vars->enemy->pos.orient == 'a')
			display_element(&vars->map.aanim_enemy->data, vars,
				vars->enemy->pos.x, vars->enemy->pos.y);
		else
			display_element(&vars->map.danim_enemy->data, vars,
				vars->enemy->pos.x, vars->enemy->pos.y);
		if (surroundings(vars, vars->enemy->pos.x, vars->enemy->pos.y, 'P'))
			destroy(vars);
		vars->enemy = vars->enemy->next;
		j++;
		i++;
	}
	if (i > 10 * vars->map.num_enemies)
		i = 0;
	vars->map.aanim_enemy = vars->map.aanim_enemy->next;
	vars->map.danim_enemy = vars->map.danim_enemy->next;
}
