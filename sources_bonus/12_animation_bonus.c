/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/16 15:28:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	side_right(t_game *game);
static void	side_left(t_game *game);

void	ft_animation(void *param)
{
	t_game	*game;
	int		time;

	game = (t_game *)param;
	time = (int)(mlx_get_time() * 100);
	tnt_animation(game, time);
	player_animation(game, time);
}

void	tnt_animation(t_game *game, int time)
{
	if (time % 13 == 0)
	{
		game->enemy_data->img->enabled = 0;
		game->tnt_data->img->enabled = 1;
	}
	else if (time % 11 == 0)
	{
		game->tnt_data->img->enabled = 0;
		game->enemy_data->img->enabled = 1;
	}
}

void	player_animation(t_game *game, int time)
{
	if (time % 13 == 1)
	{
		if (game->side == '>')
			side_right(game);
		else if (game->side == '<')
			side_left(game);
	}
}

static void	side_right(t_game *game)
{
	if (game->player_data->img->enabled == 1)
	{
		game->playerl_data->img->enabled = 0;
		game->player_m2_data->img->enabled = 0;
		game->player_data->img->enabled = 0;
		game->player_m1_data->img->enabled = 1;
	}
	else if (game->player_m1_data->img->enabled == 1)
	{
		game->playerl_data->img->enabled = 0;
		game->player_m2_data->img->enabled = 0;
		game->player_m1_data->img->enabled = 0;
		game->player_data->img->enabled = 1;
	}
}

static void	side_left(t_game *game)
{
	if (game->playerl_data->img->enabled == 1)
	{
		game->player_data->img->enabled = 0;
		game->playerl_data->img->enabled = 0;
		game->player_m1_data->img->enabled = 0;
		game->player_m2_data->img->enabled = 1;
	}
	else if (game->player_m2_data->img->enabled == 1)
	{
		game->player_data->img->enabled = 0;
		game->player_m1_data->img->enabled = 0;
		game->player_m2_data->img->enabled = 0;
		game->playerl_data->img->enabled = 1;
	}
}
