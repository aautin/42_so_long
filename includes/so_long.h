/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:51:38 by aautin            #+#    #+#             */
/*   Updated: 2023/12/31 18:38:21 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libft
# include "../libft/includes/libft_extended.h"

// mlx
# include "/home/aautin/Downloads/mlx/mlx.h"
# include "/home/aautin/Downloads/mlx/mlx_int.h"

//// PARSING
// path_finding.c
int			are_coins_accessible(char **map);
int			is_exit_accessible(char **map);
int			is_player_locked(char **map);

// map.c
int			is_file_valid(char *map_name);
int			is_format_valid(char **map);
int			is_account_valid(char **map);
int			is_map_content_valid(int map_fd);
int			is_map_valid(char *map_fl);

//// SO_LONG
// main.c
int			main(int argc, char **argv);

#endif