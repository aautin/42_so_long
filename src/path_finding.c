/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/23 21:40:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_paths(char **map)
{
	t_coords	i;

	i = init_coords(0, 0);
	while (map[++i.y])
	{
		i.x = 0;
		while (map[i.y][++i.x])
		{
			if (map[i.y][i.x] == 'C')
				return (ft_printf("Error\nA coin isn't accessible\n"), FAIL);
			if (map[i.y][i.x] == 'E')
			{
				if (ft_strchr("SC", map[i.y][i.x + 1]) == FALSE
					&& ft_strchr("SC", map[i.y][i.x - 1]) == FALSE
					&& ft_strchr("SC", map[i.y + 1][i.x]) == FALSE
					&& ft_strchr("SC", map[i.y - 1][i.x]) == FALSE)
					return (ft_printf("Error\nExit isn't accessible\n"), FAIL);
			}
		}
	}
	return (SUCCESS);
}

static char	**get_map_copy(char **map)
{
	char		**map_copy;
	t_coords	size;
	int			i;

	size = map_size(map);
	map_copy = (char **)malloc((size.y + 1) * sizeof(char *));
	if (map_copy == NULL)
	{
		ft_printf("Error\nMalloc problem\n");
		free_stab(map);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (map[++i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (map_copy == NULL)
		{
			ft_printf("Error\nMalloc problem\n");
			free_stab(map);
			free_stab(map_copy);
			exit(EXIT_FAILURE);
		}
	}
	return (map_copy[i] = NULL, map_copy);
}

static int	try_spread(char **map, t_coords i, t_coords size)
{
	int			spread;

	spread = 0;
	if (map[i.y - 1][i.x] == '0' || map[i.y - 1][i.x] == 'C')
	{
		map[i.y - 1][i.x] = 'S';
		spread = 1;
	}
	if (map[i.y][i.x - 1] == '0' || map[i.y][i.x - 1] == 'C')
	{
		map[i.y][i.x - 1] = 'S';
		spread = 1;
	}
	if (i.y + 2 != size.y && ft_strchr("0C", map[i.y + 1][i.x]) != NULL)
	{
		map[i.y + 1][i.x] = 'S';
		spread = 1;
	}
	if (i.x + 2 != size.x && ft_strchr("0C", map[i.y][i.x + 1]) != NULL)
	{
		map[i.y][i.x + 1] = 'S';
		spread = 1;
	}
	return (spread);
}

static void	path_finding(char **map)
{
	int			spread;
	t_coords	i;
	t_coords	size;

	size = map_size(map);
	spread = 1;
	while (spread == TRUE)
	{
		spread = FALSE;
		i = init_coords(0, 0);
		while (map[++i.y])
		{
			i.x = 0;
			while (map[i.y][++i.x])
			{
				if (map[i.y][i.x] == 'P' || map[i.y][i.x] == 'S')
				{
					if (try_spread(map, i, size) == SUCCESS)
						spread = TRUE;
				}
			}
		}
	}
}

// for (int x = 0; map_copy[x]; x++)
// 	ft_printf("%s\n", map_copy[x]);
void	check_map(char **map)
{
	char	**map_copy;

	map_copy = get_map_copy(map);
	path_finding(map_copy);
	if (check_paths(map_copy) == FAIL)
	{
		free_stab(map);
		free_stab(map_copy);
		exit(EXIT_FAILURE);
	}
	else
		free_stab(map_copy);
}
