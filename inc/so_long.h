/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:42:16 by aautin            #+#    #+#             */
/*   Updated: 2024/01/25 16:58:47 by aautin           ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_game
{
	t_coords	map_size;
	t_coords	scr_size;
	char		**map;
	char		**imgs_name;
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

#endif