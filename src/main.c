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

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_printf("SCR_LEN = %d || SCR_WID = %d\n", SCR_LEN, SCR_WID);
	if (argc == 2)
	{
		game.map = set_file_to_map(argv[1]);
		ft_printf("%s is correct\n", argv[1]);
		(void) game;
	}
	else
		ft_printf("Error\nWrong number of arguments\n%d", argc);
	return (0);
}
