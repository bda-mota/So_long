/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_finish_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/15 11:56:14 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_matrix(game->matrix);
	free_sprite(game, game->bg_data);
	free_sprite(game, game->player_data);
	free_sprite(game, game->collect_data);
	free_sprite(game, game->exit_data);
	free_sprite(game, game->wall_data);
	mlx_close_window(game->mlx);
}

void	free_sprite(t_game *game, t_sprites *sprite)
{
	mlx_delete_image(game->mlx, sprite->img);
	mlx_delete_texture(sprite->texture);
	free(sprite);
}
