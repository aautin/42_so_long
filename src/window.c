/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:10:28 by aautin            #+#    #+#             */
/*   Updated: 2024/01/03 17:37:54 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 17)
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

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1280, 720, "so_long");
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}
