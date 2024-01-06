/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:04:17 by aautin            #+#    #+#             */
/*   Updated: 2024/01/06 22:51:29 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_block	**alloc_blocks(char **map)
{
	t_block		**config;
	t_coords	size;
	int			line_nb;

	size = init_coords(map_len(map), map_width(map));
	config = (t_block **)malloc((size.y + 1) * sizeof(t_block *));
	if (config == NULL)
		return (NULL);
	line_nb = 0;
	while (map[line_nb])
	{
		config[line_nb] = (t_block *)malloc((size.x + 1) * sizeof(t_block));
		if (config[line_nb] == NULL)
		{
			while (config[--line_nb] && line_nb >= 0)
				free(config[line_nb]);
			free(config);
			return (NULL);
		}
		line_nb++;
	}
	config[line_nb] = NULL;
	return (config);
}

int	get_fl_name_len(t_block blk)
{
	int	len;

	len = 0;
	if (blk.left)
		len++;
	if (blk.left_u)
		len++;
	if (blk.up)
		len++;
	if (blk.right_u)
		len++;
	if (blk.right)
		len++;
	if (blk.right_d)
		len++;
	if (blk.down)
		len++;
	if (blk.left_d)
		len++;
	return (len + PATH_EXT);
}

char	*get_block_fl_name(t_block blk)
{
	char	*fl_name;
	int		fl_name_len;

	fl_name_len = get_fl_name_len(blk);
	fl_name = (char *)malloc((fl_name_len + 1) * sizeof(char));
	fl_name[0] = '\0';
	ft_strlcat(fl_name, "assets/xpm_16/", fl_name_len);
	if (blk.left)
		ft_strlcat(fl_name, "1", fl_name_len);
	if (blk.left_u)
		ft_strlcat(fl_name, "2", fl_name_len);
	if (blk.up)
		ft_strlcat(fl_name, "3", fl_name_len);
	if (blk.right_u)
		ft_strlcat(fl_name, "4", fl_name_len);
	if (blk.right)
		ft_strlcat(fl_name, "5", fl_name_len);
	if (blk.right_d)
		ft_strlcat(fl_name, "6", fl_name_len);
	if (blk.down)
		ft_strlcat(fl_name, "7", fl_name_len);
	if (blk.left_d)
		ft_strlcat(fl_name, "8", fl_name_len);
	ft_strlcat(fl_name, ".xpm", fl_name_len + 1);
	return (fl_name);
}

t_block	define_block(char **map, t_coords i, char flag)
{
	t_block	blk;

	if (flag != '\0' && flag != '1')
	{
		blk.type = map[i.y][i.x];
		define_left_config(&blk, map, i);
		define_right_config(&blk, map, i);
		define_up_down_config(&blk, map, i);
	}
	else
	{
		blk.type = flag;
		blk.left = 0;
		blk.left_u = 0;
		blk.left_d = 0;
		blk.right = 0;
		blk.right_u = 0;
		blk.right_d = 0;
		blk.up = 0;
		blk.down = 0;
	}

	return (blk);
}

t_block	**init_blocks(char **map)
{
	t_block		**map_config;
	t_coords	i;

	map_config = alloc_blocks(map);
	if (map_config == NULL)
		return (NULL);
	i = init_coords(-1, -1);
	while (map[++i.y])
	{
		i.x = -1;
		while (map[i.y][++i.x])
		{
			if (map[i.y][i.x] != '1')
				map_config[i.y][i.x] = define_block(map, i, '0');
			else
				map_config[i.y][i.x] = define_block(map, i, '1');
		}
		map_config[i.y][i.x] = define_block(map, i, '\0');
	}
	return (map_config);
}
