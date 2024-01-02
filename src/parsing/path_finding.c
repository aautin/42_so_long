/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:31:03 by aautin            #+#    #+#             */
/*   Updated: 2024/01/02 17:50:00 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	coords_access(char **map, t_coords target, t_coords pl)
{
	char	**tp_map;
	int		fd;

	if (pl.x == target.x && pl.y == target.y)
	{
		free_stab(map);
		return (1);
	}
	else
	{
		fd = 0;
		if (map[pl.y][pl.x - 1] != '1' && map[pl.y][pl.x - 1] != 'P')
		{
			tp_map = stab_dup(map);
			tp_map[pl.y][pl.x - 1] = 'P';
			fd += coords_access(tp_map, target, init_coords(pl.x - 1, pl.y));
		}
		if (map[pl.y - 1][pl.x] != '1' && map[pl.y - 1][pl.x] != 'P' && !fd)
		{
			tp_map = stab_dup(map);
			tp_map[pl.y - 1][pl.x] = 'P';
			fd += coords_access(tp_map, target, init_coords(pl.x, pl.y - 1));
		}
		if (map[pl.y][pl.x + 1] != '1' && map[pl.y][pl.x + 1] != 'P' && !fd)
		{
			tp_map = stab_dup(map);
			tp_map[pl.y][pl.x + 1] = 'P';
			fd += coords_access(tp_map, target, init_coords(pl.x + 1, pl.y));
		}
		if (map[pl.y + 1][pl.x] != '1' && map[pl.y + 1][pl.x] != 'P' && !fd)
		{
			tp_map = stab_dup(map);
			tp_map[pl.y + 1][pl.x] = 'P';
			fd += coords_access(tp_map, target, init_coords(pl.x, pl.y + 1));
		}
		free_stab(map);
		return (fd);
	}
}

int	are_coins_accessible(char **map)
{
	if (map)
		return (1);
	return (0);
}

int	is_exit_accessible(char **map)
{
	t_coords	exit;
	t_coords	player;

	exit = get_coords(map, 'E');
	player = get_coords(map, 'P');
	if (exit.x != -1 && exit.y != -1
		&& coords_access(stab_dup(map), exit, player))
		return (1);
	ft_printf("Error\nThe exit isn't accessible\n");
	return (0);
}
