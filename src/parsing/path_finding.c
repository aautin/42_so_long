/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:31:03 by aautin            #+#    #+#             */
/*   Updated: 2024/01/01 19:41:22 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_coords_accessible(char **map, t_coords target, t_coords pl)
{
	char	**temp_map;
	int		found;

	if (pl.x == target.x && pl.y == target.y)
	{
		free_stab(map);
		return (1);
	}
	else
	{
		found = 0;
		if (map[pl.y][pl.x - 1] != '1' && map[pl.y][pl.x - 1] != 'P')
		{
			temp_map = stab_dup(map);
			temp_map[pl.y][pl.x - 1] = 'P';
			found += is_coords_accessible(temp_map, target, init_coords(pl.x - 1, pl.y));
		}
		if (map[pl.y - 1][pl.x] != '1' && map[pl.y - 1][pl.x] != 'P')
		{
			temp_map = stab_dup(map);
			temp_map[pl.y - 1][pl.x] = 'P';
			found += is_coords_accessible(temp_map, target, init_coords(pl.x, pl.y - 1));
		}
		if (map[pl.y][pl.x + 1] != '1' && map[pl.y][pl.x + 1] != 'P')
		{
			temp_map = stab_dup(map);
			temp_map[pl.y][pl.x + 1] = 'P';
			found += is_coords_accessible(temp_map, target, init_coords(pl.x + 1, pl.y));
		}
		if (map[pl.y + 1][pl.x] != '1' && map[pl.y + 1][pl.x] != 'P')
		{
			temp_map = stab_dup(map);
			temp_map[pl.y + 1][pl.x] = 'P';
			found += is_coords_accessible(temp_map, target, init_coords(pl.x, pl.y + 1));
		}
		free_stab(map);
		return (found);
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
	if (exit.x != -1 && exit.y != -1 && is_coords_accessible(stab_dup(map), exit, player))
		return (1);
	ft_printf("Error\nThe exit isn't accessible\n");
	return (0);
}
