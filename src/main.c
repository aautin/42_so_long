/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:49:55 by aautin            #+#    #+#             */
/*   Updated: 2024/01/05 20:25:46 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{	
		if (is_map_valid(argv[1]))
		{
			game.map = get_map(argv[1]);
			if (game.map != NULL)
			{
				game.map_size = init_coords(map_len(game.map),
						map_width(game.map));
				game.pl = get_coords(game.map, 'P');
				game.exit = get_coords(game.map, 'E');
				init_window(&game);
			}
		}
	}
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}
