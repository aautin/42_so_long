/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:51:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/08 14:19:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft
# include "../libft/includes/libft_extended.h"

// mlx
# include "/home/aautin/Downloads/mlx/mlx.h"
# include "/home/aautin/Downloads/mlx/mlx_int.h"

# ifndef W_LEN
#  define W_LEN 200
# endif

# ifndef W_WIDTH
#  define W_WIDTH 40
# endif

# define STUCK 1
# define DETACHED 0

# define PATH_EXT 18

# define ESC 65307
# define LEFT 97
# define RIGHT 100
# define UP 119
# define DOWN 115

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
	char	*fl_name;
	void	*img;
}			t_block;

typedef struct s_game
{
	t_block		**map_config;
	t_coords	pl;
	t_coords	exit;
	t_coords	map_size;
	t_coords	window_size;
	char		img_format;
	char		**map;
	void		*mlx;
	void		*window;
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
int			is_map_content_valid(char *filename);
int			is_map_valid(char *map_fl);
// -> map.c
int			init_map(t_game *game);
int			map_len(char **map);
int			map_width(char **map);
char		**get_map(char *map_name);

// block.c
t_block		**alloc_blocks(char **map);
char		*get_block_fl_name(t_block blk, char format);
t_block		define_block(char **map, t_coords i, char flag);
t_block		**init_blocks(char **map);

// moves.c
int			go_left(t_game *game);
int			go_right(t_game *game);
int			go_up(t_game *game);
int			go_down(t_game *game);

// event.c
int			key_pressed(int keycode, t_game *game);
int			close_window(t_game *game);

// map_config.c
void		free_config(t_block **map_config, t_game *game);
void		define_left_config(t_block *blk, char **map, t_coords i);
void		define_right_config(t_block *blk, char **map, t_coords i);
void		define_up_down_config(t_block *blk, char **map, t_coords i);

// put_img.c
int			print_map(t_game *game);

// coords.c
t_coords	get_coords(char **map, char letter);
t_coords	init_coords(int x_i, int y_i);

// window.c
void		define_hooks(t_game *game);
t_coords	get_screen_size(void);
void		set_window_size(t_game *game);
int			init_game(t_game *game);
void		init_window(t_game *game);

// main.c
int			main(int argc, char **argv);

#endif