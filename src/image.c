/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautin <aautin@student.42.fr >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:18:45 by aautin            #+#    #+#             */
/*   Updated: 2024/01/27 17:08:40 by aautin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_free_img_objs(t_game *game, int limit)
{
	int	i;

	i = 0;
	while (i < limit)
	{
		mlx_destroy_image(game->mlxvar, game->imgs[i].obj);
		i++;
	}
}

static void	set_img_name(t_game *game, char **imgs_name, int len, int i)
{
	int	fd;

	fd = open(ft_strnstr(imgs_name[i], "sprites", len), O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		game->imgs[i].name = ft_strnstr(imgs_name[i], "sprites", len);
	}
	else
	{
		free_stab(imgs_name);
		do_free_img_objs(game, i);
		do_free_game(game, TRUE, FALSE, TRUE);
		do_msg_exit("Opening or read-right issue with a .xpm image");
	}
}

static void	set_img_object(t_game *game, char **imgs_name, int i)
{
	t_coords	size;

	ft_printf("%s\n", game->imgs[i].name);
	game->imgs[i].obj = mlx_xpm_file_to_image(game->mlxvar, game->imgs[i].name,
		&(size.x), &(size.y));
	if (game->imgs[i].obj == NULL)
	{
		free_stab(imgs_name);
		do_free_img_objs(game, i);
		do_free_game(game, TRUE, FALSE, TRUE);
		do_msg_exit("Malloc issue during an img creation from an .xpm file");
	}
}

static void	set_imgs(t_game *game, char **imgs_name)
{
	int	i;
	int	len;

	i = -1;
	while (++i < game->imgs_nb)
	{
		len = ft_strlen(imgs_name[i]);
		if (len < 5 || ft_strncmp(imgs_name[i] + len - 4, ".xmp", len) != EOT)
		{
			free_stab(imgs_name);
			do_free_img_objs(game, i);
			do_free_game(game, TRUE, FALSE, TRUE);
			do_msg_exit("the sprites's img has to end with the .xpm extention");
		}
		set_img_name(game, imgs_name, len, i);
		set_img_object(game, imgs_name, i);
	}
}

void	init_imgs(t_game *game)
{
	char	**imgs_name;

	imgs_name = ft_split(IMGS, ' ');
	if (imgs_name == NULL)
	{
		do_free_game(game, TRUE, FALSE, TRUE);
		do_msg_exit("Malloc issue");
	}
	game->imgs_nb = 0;
	while (imgs_name[game->imgs_nb])
		game->imgs_nb++;
	game->imgs = (t_image *)malloc((game->imgs_nb + 1) * sizeof(t_image));
	if (game->imgs == NULL)
	{
		free_stab(imgs_name);
		do_free_game(game, TRUE, FALSE, TRUE);
		do_msg_exit("Malloc issue");
	}
	set_imgs(game, imgs_name);
	free(imgs_name);
}
