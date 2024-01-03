/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:10:28 by aautin            #+#    #+#             */
/*   Updated: 2024/01/03 18:17:26 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	ft_printf("key_pressed : %d\n", keycode);
	if (keycode == ESC)
		close_window(game);
	return (0);
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_stab(game->map);
	exit(0);
}
