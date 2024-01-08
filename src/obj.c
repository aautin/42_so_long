/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:10:20 by aautin            #+#    #+#             */
/*   Updated: 2024/01/08 16:43:40 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_objs(t_game *game)
{
	t_coords	i;
	t_coords	size;

	size = init_coords(-1, -1);
	i.y = -1;
	while (game->map_config[++i.y])
	{
		i.x = -1;
		while (game->map_config[i.y][++i.x].type)
		{
			if (ft_strchr("10", game->map_config[i.y][i.x].type) == 0)
			{
				ft_printf("%dy.%dx is a %c\n", i.y, i.x, game->map_config[i.y][i.x].type);
				if (game->map_config[i.y][i.x].type == 'C')
					game->map_config[i.y][i.x].obj = mlx_xpm_file_to_image(game->window, "assets/xpm32/coin.xpm", &size.x, &size.y);
				if (game->map_config[i.y][i.x].type == 'E')
					game->map_config[i.y][i.x].obj = mlx_xpm_file_to_image(game->window, "assets/xpm32/exit.xpm", &size.x, &size.y);
			}
		}
	}
	return (1);
}
