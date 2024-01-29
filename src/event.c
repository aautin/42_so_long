/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:41:38 by aautin            #+#    #+#             */
/*   Updated: 2024/01/29 23:02:37 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	do_key_pressed_event(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		do_free_game(game, TRUE, TRUE, TRUE);
		exit(EXIT_SUCCESS);
	}
	if (keycode == A_KEY)
		ft_printf("left move\n");
	else if (keycode == W_KEY)
		ft_printf("up move\n");
	else if (keycode == S_KEY)
		ft_printf("down move\n");
	else if (keycode == D_KEY)
		ft_printf("right move\n");
	else
		ft_printf("%d\n", keycode);
	return (0);
}

static int	do_close_prgm(t_game *game)
{
	do_free_game(game, TRUE, TRUE, TRUE);
	exit(EXIT_SUCCESS);
}

void	set_events(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), do_key_pressed_event, game);
	mlx_hook(game->win, 17, 0, do_close_prgm, game);
}
