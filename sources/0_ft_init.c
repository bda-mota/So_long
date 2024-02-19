/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ft_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:46:47 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/19 12:52:56 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_variables_game(&game);
	if (validate_map(argc, argv, &game))
		return (EXIT_FAILURE);
	window(&game);
	return (0);
}

int	validate_map(int argc, char **argv, t_game *game)
{
	t_valid	map;

	if (check_arguments(argc, argv))
		return (EXIT_FAILURE);
	map.fd = open_file(argv[1]);
	if (map.fd == -1)
		return (error(WARNING_4), (EXIT_FAILURE));
	if (!check_content(map.fd, &map))
		return (EXIT_FAILURE);
	map.fd = open_file(argv[1]);
	if (map.fd == -1)
		return (error(WARNING_4), (EXIT_FAILURE));
	if (build_matrix(map.fd, game))
		return (EXIT_FAILURE);
	if (is_rectangle(game, &map))
		return (EXIT_FAILURE);
	if (surrounded_by_walls(game))
		return (EXIT_FAILURE);
	flood_fill(game);
	if (game->flag != 0)
	{
		free_matrix(game->matrix);
		return (error(WARNING_15), (EXIT_FAILURE));
	}
	return (0);
}

void	init_variables_game(t_game *game)
{
	game->cols = 0;
	game->rows = 0;
	game->collected = 0;
	game->count_moves = 0;
	game->remove_collected = 0;
	game->flag = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->mlx = NULL;
	game->player_data = NULL;
	game->wall_data = NULL;
	game->exit_data = NULL;
	game->collect_data = NULL;
	game->bg_data = NULL;
}

void	init_variables_valid(t_valid *valid)
{
	valid->fd = 0;
	valid->collectible = 0;
	valid->exit = 0;
	valid->start = 0;
	valid->invalid = 0;
	valid->size = 0;
	valid->n = 0;
}
