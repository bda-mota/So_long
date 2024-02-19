/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_build_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:20:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/08 18:53:24 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_textures(t_game *game)
{
	game->player_data = init_generic_images(game, "./textures/crash.png");
	game->wall_data = init_generic_images(game, "./textures/wall.png");
	game->exit_data = init_generic_images(game, "./textures/portal.png");
	game->exit_data->img->enabled = 0;
	game->bg_data = init_generic_images(game, "./textures/background.png");
	game->collect_data = init_generic_images(game, "./textures/apple.png");
}

t_sprites	*init_generic_images(t_game *game, char *path)
{
	t_sprites	*sprite;

	sprite = ft_calloc(sizeof(t_sprites), 1);
	if (!sprite)
		return (NULL);
	sprite->texture = mlx_load_png(path);
	sprite->img = mlx_texture_to_image
		(game->mlx, sprite->texture);
	if (!sprite->img)
		return (NULL);
	mlx_resize_image
		(
			sprite->img,
			IMG_SIZE * ZOOM,
			IMG_SIZE * ZOOM
			);
	return (sprite);
}

int	put_images(t_game *game)
{
	int	l;
	int	c;

	l = 0;
	while (game->matrix[l])
	{
		c = 0;
		while (game->matrix[l][c])
		{
			if (mlx_image_to_window(game->mlx, game->bg_data->img,
					(c * BLOCK), (l * BLOCK)) < 0)
				ft_error(game);
			if (game->matrix[l][c] == '1')
				put_wall(game, c, l);
			if (game->matrix[l][c] == 'E')
				put_exit(game, c, l);
			if (game->matrix[l][c] == 'C')
				put_collectible(game, c, l);
			c++;
		}
		l++;
	}
	put_player(game);
	return (0);
}
