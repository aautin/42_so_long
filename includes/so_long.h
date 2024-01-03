/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:51:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/03 17:27:02 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft
# include "../libft/includes/libft_extended.h"

// mlx
# include "/home/aautin/Downloads/mlx/mlx.h"
# include "/home/aautin/Downloads/mlx/mlx_int.h"

typedef struct s_coords
{
	int		x;
	int		y;
}			t_coords;

typedef struct s_game
{
	t_coords	pl;
	t_coords	exit;
	void		*mlx;
	void		*window;
	char		*fl_empty;
	char		*fl_wall;
	char		*fl_exit;
	char		*fl_coin;
	char		*fl_pl_up;
	char		*fl_pl_down;
	char		*fl_pl_left;
	char		*fl_pl_right;
	char		**map;
}				t_game;

// PARSING
// -> path_finding.c
int			is_next_to_target(t_coords pos, t_coords target);
int			try_expand(char **map, t_coords pos);
int			coords_access(char **map, t_coords target);
int			are_coins_accessible(char **map);
int			is_exit_accessible(char **map);
// -> scan_map.c
int			is_file_valid(char *map_name);
int			is_format_valid(char **map);
int			is_account_valid(char **map);
int			is_map_content_valid(int map_fd);
int			is_map_valid(char *map_fl);
// -> map.c
char		**get_map(char *map_name);

// window.c
int			key_pressed(int keycode, t_game *game);
int			close_window(t_game *game);
void		init_window(t_game *game);

// coords.c
t_coords	get_coords(char **map, char letter);
t_coords	init_coords(int x_i, int y_i);

// game.c
void		init_game(t_game *game);

// main.c
int			main(int argc, char **argv);

#endif