/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecolin <ecolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:21:39 by ecolin            #+#    #+#             */
/*   Updated: 2022/09/26 13:17:23 by ecolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct s_player {
	char	orient;
	int		x;
	int		y;
	int		collec;
}	t_player;

typedef struct s_playimg {
	int					num;
	int					id;
	t_data				data;
	struct s_playimg	*next;
}	t_playimg;

typedef struct s_enemy {
	int				id;
	t_player		pos;
	char			axis;
	int				blocs;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_map {
	char		**map;
	int			height;
	int			width;
	int			num_enemies;
	t_playimg	*aanim_knight;
	t_playimg	*danim_knight;
	t_playimg	*anim_explo;
	t_playimg	*aanim_enemy;
	t_playimg	*danim_enemy;
	t_data		floor;
	t_data		wall;
	t_data		exit;
	t_data		collec;
	t_player	*collec_access;
	t_player	*player_access;
	t_player	*exit_access;

}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_map		map;
	t_enemy		*enemy;
	t_player	player;
	t_player	exit;
	t_player	collec;
}				t_vars;

void		display_map(t_vars	*vars);
int			create_map(int fd, t_map *map);
int			valid_map(int fd, t_vars *vars);
int			not_floor(t_vars *vars, int x, int y, char c);
void		no_transparency(t_data	*b_img, t_data	*r_img);
void		create_assets(t_map	*map, t_vars *vars);
void		destroy(t_vars *vars);
void		red_cross(t_vars *vars);
t_player	find_create_player(char	**map);
int			freemap(t_map *map);
t_map		map_copy(t_map	*map);
int			valid_paths(t_map *cpy, int x, int y);
void		anim_displayer(t_playimg *anim, t_vars	*vars, int x, int y);
int			find_enemies(t_vars *vars);
int			surroundings(t_vars *vars, int x, int y, char c);
void		display_element(t_data *elem, t_vars *vars, int x, int y);
t_playimg	*create_anim(char *name, int num, t_vars *vars, char *ext);
int			init_vars(t_vars *vars);
t_playimg	*new_playimg(t_vars *vars, char *name, int id, int num);
int			movement(t_vars *vars, int y, int x, t_player *player);
void		enemy_movement(t_vars *vars, t_enemy **enemy);
void		enemy_round(t_vars *vars);
int			surroundings(t_vars *vars, int x, int y, char c);

#endif