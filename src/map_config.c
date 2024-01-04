/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:48:47 by aautin            #+#    #+#             */
/*   Updated: 2024/01/04 20:16:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_config(t_block **map_config)
{
	int	i;

	i = -1;
	while (map_config[++i])
		free(map_config[i]);
	free(map_config);
}

void	define_left_config(t_block *blk, char **map, t_coords i)
{
	(void) blk;
	(void) map;
	(void) i;
}

void	define_right_config(t_block *blk, char **map, t_coords i)
{
	(void) blk;
	(void) map;
	(void) i;
}

void	define_up_config(t_block *blk, char **map, t_coords i)
{
	(void) blk;
	(void) map;
	(void) i;
}

void	define_down_config(t_block *blk, char **map, t_coords i)
{
	(void) blk;
	(void) map;
	(void) i;
}
