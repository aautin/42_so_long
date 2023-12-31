/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:10:34 by aautin            #+#    #+#             */
/*   Updated: 2023/12/31 19:04:55 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_file_valid(char *map_name)
{
	int	fd;

	if (ft_strlen(map_name) > 3
		&& ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4) == 0)
	{
		fd = open(map_name, O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error\nThe map's file provided doesn't exist ");
			ft_printf("(or read_rights problem)\n");
			return (0);
		}
		return (fd);
	}
	else
	{
		ft_printf("Error\n");
		ft_printf("The map's name provided hasn't the '.ber' extension\n");
		return (0);
	}
}

int	is_format_valid(char **map)
{
	int	row_i;
	int	col_i;

	row_i = -1;
	while (map[++row_i])
	{
		col_i = -1;
		while (map[row_i][++col_i])
		{
			if (!row_i || !col_i || !map[row_i + 1] || !map[row_i][col_i + 1])
			{
				if (map[row_i][col_i] != '1')
					return (ft_printf("Error\nMap invalid (not closed)\n") == 0);
			}
			else if (ft_strchr("1E0PC", map[row_i][col_i]) == NULL)
				return (ft_printf("Error\nMap invalid (1E0PC only)\n") == 0);
		}
		if (col_i != (int) ft_strlen(map[0]))
			return (ft_printf("Error\nMap invalid (not a rectangle)\n") == 0);
	}
	if (row_i < 3)
		return (ft_printf("Error\nMap invalid (not large enough)\n") == 0);
	return (1);
}

int	is_account_valid(char **map)
{
	int	col_i;
	int	players_nb;
	int	coins_nb;
	int	exits_nb;

	players_nb = 0;
	coins_nb = 0;
	exits_nb = 0;
	while (*map)
	{
		col_i = -1;
		while ((*map)[++col_i])
		{
			if ((*map)[col_i] == 'P')
				players_nb++;
			if ((*map)[col_i] == 'C')
				coins_nb++;
			if ((*map)[col_i] == 'E')
				exits_nb++;
		}
		map++;
	}
	if (players_nb != 1 || coins_nb == 0 || exits_nb != 1)
		return (ft_printf("Error\nThe number of P, E and C isn't right\n") == 0);
	return (1);
}

int	is_map_content_valid(int map_fd)
{
	char	*map_content;
	char	**map;

	map_content = get_file_content(map_fd);
	if (map_content == NULL)
		return (0);
	map = ft_split(map_content, '\n');
	free(map_content);
	if (is_format_valid(map) == 0 || is_account_valid(map) == 0)
	{
		free_stab(map);
		return (0);
	}
	if (!is_exit_accessible(map) || !are_coins_accessible(map))
	{
		free_stab(map);
		return (0);
	}
	free_stab(map);
	return (1);
}

int	is_map_valid(char *map_name)
{
	int	map_fd;

	map_fd = is_file_valid(map_name);
	if (map_fd == 0)
		return (0);
	if (is_map_content_valid(map_fd) == 0)
		return (0);
	return (1);
}
