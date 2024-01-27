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

static void	set_imgs(t_image *imgs, char **imgs_name, int imgs_nb)
{
	(void) imgs;
	(void) imgs_name;
	(void) imgs_nb;
	// dup chaque string en decalant le nom jusqu'au dernier /, et ignorer .xpm
	// parsing en verifiant que l'extension est bien .xpm --> sinon free & exit
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
	set_imgs(game->imgs, imgs_name, game->imgs_nb);
	free_stab(imgs_name);
}
