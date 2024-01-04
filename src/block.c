/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:04:17 by aautin            #+#    #+#             */
/*   Updated: 2024/01/04 20:22:29 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_block	**alloc_blocks(char **map)
{
	t_block		**map_config;
	t_coords	size;
	int			line_nb;

	size = init_coords(map_len(map), map_width(map));
	map_config = (t_block **)malloc((size.y + 1) * sizeof(t_block *));
	if (map_config == NULL)
		return (NULL);
	line_nb = 0;
	while (map[line_nb])
	{
		map_config[line_nb] = (t_block *)malloc((size.x + 1) * sizeof(t_block));
		if (map_config[line_nb] == NULL)
		{
			while (map_config[--line_nb] && line_nb >= 0)
				free(map_config[line_nb]);
			free(map_config);
			return (NULL);
		}
		line_nb++;
	}
	map_config[line_nb] = NULL;
	return (map_config);
}

t_block	init_null_block(void)
{
	t_block	empty;

	empty.type = '\0';
	empty.left = 0;
	empty.left_u = 0;
	empty.left_d = 0;
	empty.right = 0;
	empty.right_u = 0;
	empty.right_d = 0;
	empty.up = 0;
	empty.down = 0;
	return (empty);
}

t_block	init_wall_block(void)
{
	t_block	wall;

	wall.type = '1';
	wall.left = 0;
	wall.left_u = 0;
	wall.left_d = 0;
	wall.right = 0;
	wall.right_u = 0;
	wall.right_d = 0;
	wall.up = 0;
	wall.down = 0;
	return (wall);
}

t_block	define_block(char **map, t_coords i)
{
	t_block	blk;

	blk.type = map[i.y][i.x];
	define_left_config(&blk, map, i);
	define_right_config(&blk, map, i);
	define_up_config(&blk, map, i);
	define_down_config(&blk, map, i);
	(void) i;
	return (blk);
}

t_block	**init_blocks(char **map)
{
	t_block		**map_config;
	t_coords	i;

	map_config = alloc_blocks(map);
	i = init_coords(-1, -1);
	while (map[++i.y])
	{
		i.x = -1;
		while (map[i.y][++i.x])
		{
			if (map[i.y][i.x] != '1')
				map_config[i.y][i.x] = define_block(map, i);
			else
				map_config[i.y][i.x] = init_null_block();
		}
		map_config[i.y][i.x] = init_null_block();
	}
	return (map_config);
}
