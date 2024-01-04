/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:51:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/04 20:16:13 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft
# include "../libft/includes/libft_extended.h"

// mlx
# include "/home/aautin/Downloads/mlx/mlx.h"
# include "/home/aautin/Downloads/mlx/mlx_int.h"

# define ESC 65307

typedef struct s_coords
{
	int		x;
	int		y;
}			t_coords;

typedef struct s_block
{
	char	type;
	char	left;
	char	left_u;
	char	up;
	char	right_u;
	char	right;
	char	right_d;
	char	down;
	char	left_d;
}			t_block;

typedef struct s_game
{
	t_block		**map_config;
	t_coords	pl;
	t_coords	exit;
	void		*mlx;
	void		*window;
	void		*img_empty;
	void		*img_wall;
	void		*img_exit;
	void		*img_coin;
	void		*img_pl_up;
	void		*img_pl_down;
	void		*img_pl_left;
	void		*img_pl_right;
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
int			init_map(t_game *game);
int			map_len(char **map);
int			map_width(char **map);
char		**get_map(char *map_name);

// block.c
t_block		**alloc_blocks(char **map);
t_block		init_null_block(void);
t_block		define_block(char **map, t_coords i);
t_block		**init_blocks(char **map);

// window.c
int			key_pressed(int keycode, t_game *game);
int			close_window(t_game *game);

// map_config.c
void		free_config(t_block **map_config);
void		define_left_config(t_block *blk, char **map, t_coords i);
void		define_right_config(t_block *blk, char **map, t_coords i);
void		define_up_config(t_block *blk, char **map, t_coords i);
void		define_down_config(t_block *blk, char **map, t_coords i);


// coords.c
t_coords	get_coords(char **map, char letter);
t_coords	init_coords(int x_i, int y_i);

// game.c
void		define_hooks(t_game *game);
void		init_game(t_game *game);

// main.c
int			main(int argc, char **argv);

#endif