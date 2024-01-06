/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:55:57 by aautin            #+#    #+#             */
/*   Updated: 2024/01/06 17:13:41 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	define_hooks(t_game *game)
{
	mlx_key_hook(game->window, key_pressed, game);
	mlx_hook(game->window, 17, 0, close_window, game);
}

void	set_window_size(t_game *game)
{
	if (game->map_size.x * 64 <= W_LEN && game->map_size.y * 64 <= W_WIDTH)
	{
		game->window_size.x = game->map_size.x * 64;
		game->window_size.y = game->map_size.y * 64;
		game->img_format = "64";
	}
	else
	{
		game->window_size.x = game->map_size.x * 32;
		game->window_size.y = game->map_size.y * 32;
		game->img_format = "32";
	}
}

int	init_game(t_game *game)
{
	
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	set_window_size(game);
	if (init_game(game) == 0)
		close_window(game);
	game->window = mlx_new_window(game->mlx, game->window_size.x,
			game->window_size.y, "so_long");
	ft_printf("map_len      : %d\n", game->map_size.x);
	ft_printf("map_width    : %d\n", game->map_size.y);
	ft_printf("wdw_len      : %d\n", game->window_size.x);
	ft_printf("wdw_width    : %d\n", game->window_size.y);
	ft_printf("format       : %s\n", game->img_format);
	define_hooks(game);
	if (init_map(game) == 1)
		mlx_loop(game->mlx);
	else
		close_window(game);
}
