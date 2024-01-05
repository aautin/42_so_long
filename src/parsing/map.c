/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:46:30 by aautin            #+#    #+#             */
/*   Updated: 2024/01/05 18:41:31 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_map(t_game *game)
{
	game->map_config = init_blocks(game->map);
	if (game->map_config == NULL)
		return (0);
	put_walls(game);
	return (1);
}

int	map_len(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	map_width(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**get_map(char *map_name)
{
	char	*temp_map;
	char	**map;

	temp_map = get_file_content(map_name);
	if (temp_map == NULL)
		return (NULL);
	map = ft_split(temp_map, '\n');
	if (map == NULL)
		return (NULL);
	free(temp_map);
	return (map);
}
