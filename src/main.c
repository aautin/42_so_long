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

static char	*get_map_content(char *mapfile)
{
	char	*file_content;

	file_content = get_file_content(mapfile);
	if (file_content == NULL)
	{
		ft_printf("Error\nMalloc problem or empty mapfile\n");
		exit(EXIT_FAILURE);
	}
	return (file_content);
}

static t_coords	get_map_size(char *file_content)
{
	t_coords	size;
	int			i;

	size.x = 0;
	while(file_content[size.x] && file_content[size.x] != '\n')
		size.x++;
	i = 0;
	size.y = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n')
		{
			if ((i - size.y) % size.x != 0)
			{
				ft_printf("Error\nThe map isn't a rectangle\n");
				free(file_content);
				exit(EXIT_FAILURE);
			}
			size.y++;
		}
		i++;
	}
	return (size);
}

static char	**get_map(char *file_content)
{
	int	i;
	t_coords	size;

	size = get_map_size(file_content);
	ft_printf("size.x == %d || size.y == %d\n", size.x, size.y);
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
	return (NULL);
}

char	**file_to_map(char *mapfile)
{
	char	*file_content;
	char	**map;

	check_file(mapfile);
	file_content = get_map_content(mapfile);
	map = get_map(file_content);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.map = file_to_map(argv[1]);
		(void) game;
	}
	else
		ft_printf("Error\nWrong number of arguments\n");
	return (0);
}
