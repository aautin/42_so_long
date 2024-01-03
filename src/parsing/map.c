/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:46:30 by aautin            #+#    #+#             */
/*   Updated: 2024/01/03 20:34:58 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_map(t_game *game)
{
	int	width;
	int	height;
	width = 0;
	height = 0;
	game->img_pl_down = mlx_xpm_file_to_image(game->mlx, "assets/xpm/pl_down.xpm", &width, &height);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "assets/xpm/empty0011.xpm", &width, &height);
	mlx_put_image_to_window(game->mlx, game->window, game->img_empty, 100, 100);
	mlx_put_image_to_window(game->mlx, game->window, game->img_pl_down, 100, 100);
	ft_printf("width : %d\n", width);
	ft_printf("height: %d\n", height);
}

char	**get_map(char *map_name)
{
	int		fd;
	char	*temp_map;
	char	**map;

	fd = is_file_valid(map_name);
	if (fd == 0)
		return (NULL);
	temp_map = get_file_content(fd);
	if (temp_map == NULL)
		return (NULL);
	map = ft_split(temp_map, '\n');
	if (map == NULL)
		return (NULL);
	free(temp_map);
	return (map);
}
