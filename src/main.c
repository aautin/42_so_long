/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/23 21:40:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_scr_map_compatibility(t_game *game)
{
	ft_printf("SCR_LEN=%d SCR_WID=%d\n", game->scr_size.x, game->scr_size.y);
	ft_printf("MAP_LEN=%d MAP_WID=%d\n", game->map_size.x, game->map_size.y);
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
		// game.imgs_name = ft_split(IMGS, ' ');
		// if (game.imgs_name == NULL)
		// {
		// 	free_stab(game.map);
		// 	do_msg_exit("Malloc problem");
		// }
		// for (int x = 0; game.imgs_name[x]; x++)
		// 	ft_printf("%s\n", game.imgs_name[x]);
		(void) game;
	}
	else
		ft_printf("Error\nWrong number of arguments\n%d", argc);
	return (0);
}
