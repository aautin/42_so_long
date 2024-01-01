/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:21:24 by aautin            #+#    #+#             */
/*   Updated: 2024/01/01 18:11:23 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coords	get_coords(char **map, char letter)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == letter)
				return (init_coords(x, y));
		}
	}
	return (init_coords(-1, -1));
}

t_coords	init_coords(int x_i, int y_i)
{
	t_coords	element;

	element.x = x_i;
	element.y = y_i;
	return (element);
}
