/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/27 17:15:35 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_scr_map_compatibility(t_game *game)
{
	int	check;

	check = SUCCESS;
	if (game->scr_size.x < (game->map_size.x * 32))
	{
		check = FAIL;
		ft_printf("Error\nThe map length is bigger than the screen length\n");
	}
	if (game->scr_size.y < (game->map_size.y * 32))
	{
		check = FAIL;
		ft_printf("Error\nThe map width is bigger than the screen width\n");
	}
	if (check == FAIL)
	{
		free_stab(game->map);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.map = get_map_from_file(argv[1]);
		game.map_size = get_map_size(game.map);
		game.scr_size = init_coords(SCR_LEN, SCR_WID);
		check_scr_map_compatibility(&game);
		set_window(&game);
		init_imgs(&game);
	}
	else
		ft_printf("Error\nWrong number of arguments\n%d", argc);
	do_free_game(&game, TRUE, TRUE, TRUE);
	return (0);
}
