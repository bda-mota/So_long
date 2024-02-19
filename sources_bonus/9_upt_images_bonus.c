/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_upt_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:19:25 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/16 15:28:32 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	upt_exit(t_game *game)
{
	if (game->remove_collected == 0)
		game->exit_data->img->enabled = 1;
	if ((game->player_data->img->instances->x
			== game->exit_data->img->instances->x)
		&& (game->player_data->img->instances->y
			== game->exit_data->img->instances->y)
		&& game->exit_data->img->enabled == 1)
	{
		ft_printf("You win!!!\n");
		hook_close(game);
	}
}

void	upt_collectible(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collected)
	{
		if ((game->player_data->img->instances->x
				== game->collect_data->img->instances[i].x)
			&& (game->player_data->img->instances->y
				== game->collect_data->img->instances[i].y))
		{
			if (game->collect_data->img->instances[i].enabled)
			{
				game->collect_data->img->instances[i].enabled = false;
				game->remove_collected--;
			}
		}
		i++;
	}
}

void	upt_player(t_game *game, char side)
{
	if (side == 'l')
	{
		game->side = '<';
		game->player_data->img->enabled = 0;
		game->player_m1_data->img->enabled = 0;
		game->playerl_data->img->enabled = 1;
		game->player_data->img->instances[0].x -= 64;
		game->playerl_data->img->instances[0].x -= 64;
		game->player_m1_data->img->instances[0].x -= 64;
		game->player_m2_data->img->instances[0].x -= 64;
	}
	else if (side == 'r')
	{
		game->side = '>';
		game->playerl_data->img->enabled = 0;
		game->player_m2_data->img->enabled = 0;
		game->player_data->img->enabled = 1;
		game->player_data->img->instances[0].x += 64;
		game->playerl_data->img->instances[0].x += 64;
		game->player_m1_data->img->instances[0].x += 64;
		game->player_m2_data->img->instances[0].x += 64;
	}
}

void	move_player(t_game *game, char mov)
{
	if (mov == 's')
	{
		game->player_data->img->instances[0].y += 64;
		game->playerl_data->img->instances[0].y += 64;
		game->player_m1_data->img->instances[0].y += 64;
		game->player_m2_data->img->instances[0].y += 64;
	}
	else if (mov == 'w')
	{
		game->player_data->img->instances[0].y -= 64;
		game->playerl_data->img->instances[0].y -= 64;
		game->player_m1_data->img->instances[0].y -= 64;
		game->player_m2_data->img->instances[0].y -= 64;
	}
	else if (mov == 'a')
		upt_player(game, 'l');
	else if (mov == 'd')
		upt_player(game, 'r');
}
