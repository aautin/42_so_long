/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:41:40 by aautin            #+#    #+#             */
/*   Updated: 2024/01/23 21:40:32 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *mapfile)
{
	int	len;
	int	fd;

	len = ft_strlen(mapfile);
	if (ft_strncmp(mapfile + (len - 4), ".ber", len) != 0)
	{
		ft_printf("Error\n");
		ft_printf("The extension of the mapfile has to be '.ber'\n");
		exit(EXIT_FAILURE);
	}
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		ft_printf("Access or rights issue with the mapfile\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	check_map_size(char *file_content)
{
	t_coords	size;
	int			i;

	size.x = 0;
	while (file_content[size.x] && file_content[size.x] != '\n')
		size.x++;
	if (file_content[size.x] == '\0')
	{
		ft_printf("Error\nThe map isn't a rectangle\n");
		free(file_content);
		exit(EXIT_FAILURE);
	}
	i = -1;
	size.y = 0;
	while (file_content[++i])
	{
		if (file_content[i] == '\n' && ((i - size.y++) % size.x != 0))
		{
			ft_printf("Error\nThe map isn't a rectangle\n");
			free(file_content);
			exit(EXIT_FAILURE);
		}
	}
}

static void	check_game_elements(char *file_content)
{
	int	exits_nb;
	int	players_nb;
	int	coins_nb;
	int	i;

	exits_nb = 0;
	players_nb = 0;
	coins_nb = 0;
	i = -1;
	while (file_content[++i])
	{
		if (file_content[i] == 'E')
			exits_nb++;
		if (file_content[i] == 'P')
			players_nb++;
		if (file_content[i] == 'C')
			coins_nb++;
	}
	if (exits_nb != 1 || players_nb != 1 || coins_nb == 0)
	{
		ft_printf("Error\nThe map has to contains: ");
		ft_printf("1 player, 1 exit and at least 1 coin\n");
		free(file_content);
		exit(EXIT_FAILURE);
	}
}

static char	**get_map(char *file_content)
{
	char	**map;
	int		i;

	check_map_size(file_content);
	i = -1;
	while (file_content[++i])
	{
		if (ft_strchr("10PCE\n", file_content[i]) == False)
		{
			ft_printf("Error\nThe map contains an invalid character ");
			ft_printf("(only '10PCE allowed')\n");
			free(file_content);
			exit(EXIT_FAILURE);
		}
	}
	check_game_elements(file_content);
	map = ft_split(file_content, '\n');
	free(file_content);
	if (map == NULL)
	{
		ft_printf("Error\nMalloc problem\n");
		exit(EXIT_FAILURE);
	}
	return (map);
}

char	**set_file_to_map(char *mapfile)
{
	char		*file_content;
	char		**map;

	check_file(mapfile);
	file_content = get_file_content(mapfile);
	if (file_content == NULL)
	{
		ft_printf("Error\nNo content during the mapfile to read\n");
		ft_printf("Malloc problem or empty mapfile\n");
		exit(EXIT_FAILURE);
	}
	map = get_map(file_content);
	check_map(map);
	return (map);
}
