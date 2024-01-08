/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:10:28 by aautin            #+#    #+#             */
/*   Updated: 2024/01/08 14:18:49 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_window(game);
	else if (keycode == LEFT)
		go_left(game);
	else if (keycode == RIGHT)
		go_right(game);
	else if (keycode == UP)
		go_up(game);
	else if (keycode == DOWN)
		go_down(game);
	else
		ft_printf("key_pressed : %d\n", keycode);
	return (0);
}

int	close_window(t_game *game)
{
	free_config(game->map_config, game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_stab(game->map);
	free(game->mlx);
	exit(0);
}
