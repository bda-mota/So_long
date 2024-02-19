/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_start_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:20:59 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/19 13:04:16 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	key_pressed(mlx_key_data_t keydata, keys_t k1, keys_t k2);
static void	hook_key_press(mlx_key_data_t keydata, void *param);

static int	key_pressed(mlx_key_data_t keydata, keys_t k1, keys_t k2)
{
	return ((keydata.key == k1 || keydata.key == k2)
		&& keydata.action == MLX_PRESS);
}

static void	hook_key_press(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		hook_close(game);
		return ;
	}
	if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		if (valid_moves(game, 'y', '-') == 0)
			game->player_data->img->instances[0].y -= 64;
	if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		if (valid_moves(game, 'y', '+') == 0)
			game->player_data->img->instances[0].y += 64;
	if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		if (valid_moves(game, 'x', '-') == 0)
			game->player_data->img->instances[0].x -= 64;
	if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		if (valid_moves(game, 'x', '+') == 0)
			game->player_data->img->instances[0].x += 64;
	upt_collectible(game);
	upt_exit(game);
	return ;
}

int	window(t_game *game)
{
	int	max_col;
	int	max_lin;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	max_col = BLOCK * game->cols;
	max_lin = BLOCK * game->rows;
	game->mlx = mlx_init(max_col, max_lin, "So long", true);
	if (!game->mlx)
		ft_error(game);
	init_textures(game);
	put_images(game);
	mlx_key_hook(game->mlx, hook_key_press, game);
	mlx_close_hook(game->mlx, hook_close, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
