/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_upt_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:19:25 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/15 12:13:07 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	upt_exit(t_game *game)
{
	if (game->remove_collected == 0)
		game->exit_data->img->enabled = 1;
	if ((game->player_data->img->instances->x
			== game->exit_data->img->instances->x)
		&& (game->player_data->img->instances->y
			== game->exit_data->img->instances->y)
		&& game->exit_data->img->enabled == 1)
		hook_close(game);
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
