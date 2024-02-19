/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_put_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:02:42 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/16 16:49:50 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	put_collectible(t_game *game, int c, int l)
{
	game->collected++;
	game->remove_collected++;
	if (mlx_image_to_window(game->mlx, game->collect_data->img,
			(c * BLOCK), (l * BLOCK)) < 0)
		ft_error(game);
	return (0);
}

int	put_wall(t_game *game, int c, int l)
{
	if (mlx_image_to_window(game->mlx, game->wall_data->img,
			(c * BLOCK), (l * BLOCK)) < 0)
		ft_error(game);
	return (0);
}

int	put_player(t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->player_data->img,
			(game->player_x * BLOCK), (game->player_y * BLOCK)) < 0)
		ft_error(game);
	game->player_data->x = game->player_x;
	game->player_data->y = game->player_y;
	return (0);
}

int	put_exit(t_game *game, int c, int l)
{
	if (mlx_image_to_window(game->mlx, game->exit_data->img,
			(c * BLOCK), (l * BLOCK)) < 0)
		ft_error(game);
	return (0);
}
