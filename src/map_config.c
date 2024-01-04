/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:48:47 by aautin            #+#    #+#             */
/*   Updated: 2024/01/04 20:43:42 by aautin           ###   ########.fr       */
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
	if (map[i.y][i.x - 1] != '1')
	{
		blk->left = STUCK;
		if (map[i.y - 1][i.x] != '1')
			blk->left_u = STUCK;
		else
			blk->left_u = DETACHED;
		if (map[i.y + 1][i.x] != '1')
			blk->left_u = STUCK;
		else
			blk->left_u = DETACHED;
	}
	else
	{
		blk->left = DETACHED;
		blk->left_u = DETACHED;
		blk->left_d = DETACHED;
	}
}

void	define_right_config(t_block *blk, char **map, t_coords i)
{
	if (map[i.y][i.x + 1] != '1')
	{
		blk->right = STUCK;
		if (map[i.y - 1][i.x] != '1')
			blk->right_u = STUCK;
		else
			blk->right_u = DETACHED;
		if (map[i.y + 1][i.x] != '1')
			blk->right_u = STUCK;
		else
			blk->right_u = DETACHED;
	}
	else
	{
		blk->right = DETACHED;
		blk->right_u = DETACHED;
		blk->right_d = DETACHED;
	}
}

void	define_up_config(t_block *blk, char **map, t_coords i)
{
	if (map[i.y - 1][i.x] != '1')
		blk->up = STUCK;
	else
		blk->up = DETACHED;
}

void	define_down_config(t_block *blk, char **map, t_coords i)
{
	if (map[i.y + 1][i.x] != '1')
		blk->down = STUCK;
	else
		blk->down = DETACHED;
}
