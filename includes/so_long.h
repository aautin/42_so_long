/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:51:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/02 18:46:12 by aautin           ###   ########.fr       */
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

// PARSING
// -> path_finding.c
int			is_next_to_target(t_coords pos, t_coords target);
int			try_expand(char **map, t_coords pos);
int			coords_access(char **map, t_coords target);
int			are_coins_accessible(char **map);
int			is_exit_accessible(char **map);
// -> map.c
int			is_file_valid(char *map_name);
int			is_format_valid(char **map);
int			is_account_valid(char **map);
int			is_map_content_valid(int map_fd);
int			is_map_valid(char *map_fl);

// coords.c
t_coords	get_coords(char **map, char letter);
t_coords	init_coords(int x_i, int y_i);

// main.c
int			main(int argc, char **argv);

#endif