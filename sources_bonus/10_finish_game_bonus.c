/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_finish_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:31 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/19 13:08:49 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	touch_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemyqtd)
	{
		if ((game->player_data->img->instances->x
				== game->enemy_data->img->instances[i].x)
			&& (game->player_data->img->instances->y
				== game->enemy_data->img->instances[i].y))
		{
			ft_printf("OH NO! You touch the enemy... try again?\n");
			hook_close(game);
			return (1);
		}
		i++;
	}
	return (0);
}

void	hook_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_matrix(game->matrix);
	free_sprite(game, game->bg_data);
	free_sprite(game, game->player_data);
	free_sprite(game, game->playerl_data);
	free_sprite(game, game->player_m1_data);
	free_sprite(game, game->player_m2_data);
	free_sprite(game, game->collect_data);
	free_sprite(game, game->exit_data);
	free_sprite(game, game->wall_data);
	free_sprite(game, game->enemy_data);
	free_sprite(game, game->tnt_data);
	free_sprite(game, game->ironwall_data);
	mlx_delete_image(game->mlx, game->txt_steps);
	mlx_delete_image(game->mlx, game->count_steps);
	mlx_close_window(game->mlx);
}

void	free_sprite(t_game *game, t_sprites *sprite)
{
	mlx_delete_image(game->mlx, sprite->img);
	mlx_delete_texture(sprite->texture);
	free(sprite);
}
