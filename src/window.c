/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:55:57 by aautin            #+#    #+#             */
/*   Updated: 2024/01/08 16:44:11 by aautin           ###   ########.fr       */
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
		game->img_format = 64;
	}
	else
	{
		game->window_size.x = game->map_size.x * 32;
		game->window_size.y = game->map_size.y * 32;
		game->img_format = 32;
	}
}

int	init_img(t_game *game, t_coords i)
{
	if (game->map_config[i.y][i.x].type != '1')
	{
		game->map_config[i.y][i.x].fl_name = get_block_fl_name(
				game->map_config[i.y][i.x], game->img_format);
		if (game->map_config[i.y][i.x].fl_name == NULL)
			return (0);
	}
	else
	{
		if (game->img_format == 64)
			game->map_config[i.y][i.x].fl_name = "assets/xpm64/w.xpm";
		else
			game->map_config[i.y][i.x].fl_name = "assets/xpm32/w.xpm";
		if (game->map_config[i.y][i.x].fl_name == NULL)
			return (0);
	}
	return (1);
}

int	init_game(t_game *game)
{
	t_coords	i;

	i = init_coords(-1, -1);
	while (game->map_config[++i.y])
	{
		i.x = -1;
		while (game->map_config[i.y][++i.x].type)
		{
			if (init_img(game, i) == 0)
				return (0);
		}
	}
	return (1);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	set_window_size(game);
	game->window = mlx_new_window(game->mlx, game->window_size.x,
			game->window_size.y, "so_long");
	ft_printf("screen_len   : %d\n", W_LEN);
	ft_printf("screen_width : %d\n", W_WIDTH);
	ft_printf("map_len      : %d\n", game->map_size.x);
	ft_printf("map_width    : %d\n", game->map_size.y);
	ft_printf("wdw_len      : %d\n", game->window_size.x);
	ft_printf("wdw_width    : %d\n", game->window_size.y);
	ft_printf("format       : %d\n", game->img_format);
	define_hooks(game);
	if (init_map(game) == 1)
	{
		if (init_game(game) == 0 || print_map(game) == 0 || print_objs(game) == 0)
			close_window(game);
		mlx_loop(game->mlx);
	}
	else
		close_window(game);
}
