/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:55:57 by aautin            #+#    #+#             */
/*   Updated: 2024/01/04 20:44:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	define_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_pressed, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1280, 720, "so_long");
	define_hooks(game);
	if (init_map(game) == 1)
		mlx_loop(game->mlx);
	else
		close_window(game);
}
