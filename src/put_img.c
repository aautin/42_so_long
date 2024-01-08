/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:55:06 by aautin            #+#    #+#             */
/*   Updated: 2024/01/08 14:13:30 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	print_map(t_game *game)
{
	t_coords	i;
	t_coords	size;

	size = init_coords(-1, -1);
	i = init_coords(-1, -1);
	while (game->map_config[++i.y])
	{
		i.x = -1;
		while (game->map_config[i.y][++i.x].type)
		{
			game->map_config[i.y][i.x].img = mlx_xpm_file_to_image(game->mlx,
					game->map_config[i.y][i.x].fl_name,
					&size.x, &size.y);
			mlx_put_image_to_window(game->mlx, game->window,
				game->map_config[i.y][i.x].img, i.x * game->img_format,
				i.y * game->img_format);
		}
	}
	return (1);
}
