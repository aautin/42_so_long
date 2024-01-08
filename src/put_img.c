/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:55:06 by aautin            #+#    #+#             */
/*   Updated: 2024/01/06 23:07:54 by aautin           ###   ########.fr       */
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
			if (game->map_config[i.y][i.x].type != '1')
			{
				ft_printf("%d | %d --> %s\n", i.x, i.y,
					game->map_config[i.y][i.x].fl_name);
				mlx_put_image_to_window(game->mlx, game->window,
					mlx_xpm_file_to_image(game->mlx,
						game->map_config[i.y][i.x].fl_name,
						&size.x, &size.y), i.x * 16, i.y * 16);
			}
		}
	}
	return (1);
}
