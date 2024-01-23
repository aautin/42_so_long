/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:42:16 by aautin            #+#    #+#             */
/*   Updated: 2024/01/23 21:23:48 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft_extended.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

# define TRUE 1
# define FALSE 0

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_game
{
	char	**map;
}	t_game;

char	**file_to_map(char *mapfile);

#endif