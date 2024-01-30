/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:42:16 by aautin            #+#    #+#             */
/*   Updated: 2024/01/30 02:06:57 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft_extended.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# ifndef SCR_LEN
#  define SCR_LEN 500
# endif
# ifndef SCR_WID
#  define SCR_WID 500
# endif
# ifndef IMGS
#  define IMGS "Error\n"
# endif

# define ESC_KEY 65307
# define A_KEY 97
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define EOT 3

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_image
{
	t_img	*obj;
	char	*name;
}	t_image;

typedef struct s_game
{
	t_coords	scr_size;
	t_coords	map_size;
	char		**map;
	int			imgs_nb;
	t_image		*imgs;
	t_xvar		*mlxvar;
	void		*win;
	int			moves_nb;
	int			coins_nb;
	t_coords	player_i;
}	t_game;

/*
* Takes as a parameter a map's path/to/file, reads it and returns a
* dble array of it no erros happens and the map's content is right.
* Otherwise, an error_msg is printed and exit(EXIT_FAILURE) executed.
*/
char		**get_map_from_file(char *mapfile);

/*
* Browses into a map and spreads a trace on each of the blocks
* accessible to the player (E coords). Then checks if every C and E
* are surrounded by a trace on the left, right, top or bottom.
* If not, free the map and exit(EXIT_FAILURE). 
*/
void		check_map(char **map);

/*
* Counts the number of char* until the NULL element (size.y) and
* counts the number of char in the 1st char* until the \0 (size.x)
* Returns the t_coords result which is the size of the map given.
*/
t_coords	get_map_size(char **map);

/*
* Takes two integers (x, y) and assigns them to the t_coords that the
* functions created, then returns the t_coords.
*/
t_coords	init_coords(int x, int y);

/*
* Prints Error\n followed by the msg param and a newline
* Then it exits with the EXIT_FAILURE status.
*/
void		do_msg_exit(char *msg);

/*
* Inits the game->mlxvar and game->win variables. If an init goes
* wrong, frees malloc vars of t_game and do_msg_exit(PERSO MSG)
*/
void		set_window(t_game *game);

/*
* Allocates game->imgs and init a name (char *) and an obj (t_img)
* for each element of the game->imgs array 
*/
void		init_imgs(t_game *game);

/*
* Used to free the content of t_game type:
* -freemlx == TRUE: mlxvar and win
* -freemap == TRUE: map
* -freeimgs == TRUE: imgs->img & ->name... then imgs
*/
void		do_free_game(t_game *game, char freemlx,
				char freeimgs, char freemap);

/*
* To complete...
*/
void		*get_img_obj(t_game *game, char *keyword);

/*
* To complete...
*/
void		put_map(t_game *game);

/*
* To complete...
*/
void		set_events(t_game *game);

/*
* To complete...
*/
void		do_try_move(t_coords move, t_game *game);

#endif