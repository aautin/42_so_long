/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:49:55 by aautin            #+#    #+#             */
/*   Updated: 2024/01/01 18:05:09 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{	
		if (is_map_valid(argv[1]))
		{
			ft_printf("No error\n");
		}
	}
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}
