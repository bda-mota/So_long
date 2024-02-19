/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:19:19 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/15 16:28:05 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	put_ironwall(t_game *game)
{
	if (mlx_image_to_window(game->mlx, game->ironwall_data->img, 0, 0 < 0))
		ft_error(game);
	mlx_resize_image
	(
		game->ironwall_data->img,
		IMG_SIZE * 8,
		IMG_SIZE * ZOOM
		);
	game->txt_steps = mlx_put_string(game->mlx, "Steps:", 23, 22);
	upt_steps(game);
	return (0);
}

void	upt_steps(t_game *game)
{
	char	*steps;

	if (game->count_steps)
		mlx_delete_image(game->mlx, game->count_steps);
	steps = ft_itoa(game->count_moves);
	game->count_steps = mlx_put_string(game->mlx, steps, 85, 23);
	free(steps);
}
