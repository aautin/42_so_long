/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:31:03 by aautin            #+#    #+#             */
/*   Updated: 2024/01/02 19:52:25 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_next_to_target(t_coords pos, t_coords target)
{
	if (pos.x == target.x)
	{
		if (pos.y == target.y - 1 || pos.y == target.y + 1)
			return (1);
	}
	else if (pos.y == target.y)
	{
		if (pos.x == target.x - 1 || pos.x == target.x + 1)
			return (1);
	}
	return (0);
}

int	try_expand(char **map, t_coords pos)
{
	int	expanded;

	expanded = 0;
	if (pos.x && strchr("1P", map[pos.y][pos.x - 1]) == 0)
	{
		map[pos.y][pos.x - 1] = 'P';
		expanded++;
	}
	if (map[pos.y][pos.x + 1] && strchr("1P", map[pos.y][pos.x + 1]) == 0)
	{
		map[pos.y][pos.x + 1] = 'P';
		expanded++;
	}
	if (pos.y && strchr("1P", map[pos.y - 1][pos.x]) == 0)
	{
		map[pos.y - 1][pos.x] = 'P';
		expanded++;
	}
	if (map[pos.y + 1][pos.x] && strchr("1P", map[pos.y + 1][pos.x]) == 0)
	{
		map[pos.y + 1][pos.x] = 'P';
		expanded++;
	}
	return (expanded);
}

int	coords_access(char **map, t_coords target)
{
	t_coords	pos;
	int			expanded;

	expanded = 1;
	while (expanded--)
	{
		pos.y = -1;
		while (map[++pos.y])
		{
			pos.x = -1;
			while (map[pos.y][++pos.x])
			{
				if (map[pos.y][pos.x] == 'P')
				{
					if (is_next_to_target(pos, target))
						return (1);
					else
						expanded += try_expand(map, pos);
				}
			}
		}
	}
	return (0);
}

int	are_coins_accessible(char **map)
{
	t_coords	pos;
	char		**test_map;

	pos = init_coords(-1, -1);
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == 'C')
			{
				test_map = stab_dup(map);
				if (test_map == NULL)
					return (0);
				if (!coords_access(test_map, pos))
				{
					ft_printf("Error\nA coin isn't accessible\n");
					free_stab(test_map);
					return (0);
				}
				free_stab(test_map);
			}
		}
	}
	return (1);
}

int	is_exit_accessible(char **map)
{
	t_coords	exit;
	char		**test_map;

	exit = get_coords(map, 'E');
	test_map = stab_dup(map);
	if (test_map == NULL)
		return (0);
	if (exit.x != -1 && exit.y != -1 && coords_access(test_map, exit))
	{
		free_stab(test_map);
		return (1);
	}
	free_stab(test_map);
	ft_printf("Error\nThe exit isn't accessible\n");
	return (0);
}
