/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:28:17 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/26 13:42:33 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_movement(t_vars *vars, t_player *tmp)
{
	static int	i;

	not_floor(vars, tmp->x, tmp->y, 0);
	not_floor(vars, vars->player.x, vars->player.y, vars->player.orient);
	ft_printf("Movement: %d\n", ++i);
	if (surroundings(vars, vars->player.x, vars->player.y, 'X')
		|| surroundings(vars, vars->player.x, vars->player.y, 'Y'))
		destroy(vars);
}

int	key_hook(int keycode, t_vars *vars)
{
	int			ex;
	t_player	tmp;

	ex = -1;
	tmp.x = vars->player.x;
	tmp.y = vars->player.y;
	if (keycode == 65307)
		destroy(vars);
	if (keycode == 'q')
		keycode = 'a';
	if (keycode == 'd' || keycode == 'a')
		vars->player.orient = keycode;
	if (keycode == 'w' || keycode == 'z')
		ex = movement(vars, -1, 0, &vars->player);
	else if (keycode == 'a')
		ex = movement(vars, 0, -1, &vars->player);
	else if (keycode == 's')
		ex = movement(vars, 1, 0, &vars->player);
	else if (keycode == 'd')
		ex = movement(vars, 0, 1, &vars->player);
	if (!ex)
		display_movement(vars, &tmp);
	return (0);
}

void	next_image(t_vars *vars, t_playimg **anim, int x, int y)
{
	usleep(50000);
	display_element(&(*anim)->data, vars, x, y);
	(*anim) = (*anim)->next;
}

int	render_next_frame(t_vars *vars)
{
	usleep(60000);
	if (vars->player.orient == 'd')
		next_image(vars, &vars->map.danim_knight,
			vars->player.x, vars->player.y);
	else
		next_image(vars, &vars->map.aanim_knight,
			vars->player.x, vars->player.y);
	if (vars->map.num_enemies)
		enemy_round(vars);
	if (vars->player.collec == vars->collec.collec
		&& vars->collec.collec && !vars->exit.orient)
	{
		next_image(vars, &vars->map.anim_explo, vars->exit.x, vars->exit.y);
		if (vars->map.anim_explo->id == 0)
		{
			vars->exit.orient = 1;
			not_floor(vars, vars->exit.x, vars->exit.y, 0);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	vars;

	vars.collec.collec = 0;
	vars.map.height = 0;
	vars.exit.collec = 0;
	if (argc != 2 || ft_strncmp(".ber", &argv[1][ft_strlen(argv[1]) - 4], 5)
			|| open(argv[1], O_DIRECTORY) > 0)
		return (ft_printf("Error: Fichier .ber non conforme.\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Fichier non existant.\n"), 0);
	if (!valid_map(fd, &vars))
		return (ft_printf("Error: Map non conforme.\n"), 0);
	close(fd);
	if (fd != open(argv[1], O_RDONLY) || !create_map(fd, &vars.map)
		|| !init_vars(&vars))
		return (ft_printf("Error\n"), 0);
	display_map(&vars);
	mlx_key_hook (vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, (void *) destroy, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
