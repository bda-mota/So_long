/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_movements_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:11:05 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/16 14:30:45 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	valid_position_y(t_game *game, char op);
static int	valid_position_x(t_game *game, char op);

int	valid_moves(t_game *game, char position, char op)
{
	int	result;

	result = 0;
	if (position == 'x')
		result = valid_position_x(game, op);
	else if (position == 'y')
		result = valid_position_y(game, op);
	return (result);
}

static int	valid_position_x(t_game *game, char op)
{
	if (op == '+'
		&& game->matrix[game->player_data->y][game->player_data->x + 1] != '1')
	{
		game->player_data->x++;
		game->count_moves++;
		upt_steps(game);
		return (0);
	}
	else if (op == '-'
		&& game->matrix[game->player_data->y][game->player_data->x - 1] != '1')
	{
		game->player_data->x--;
		game->count_moves++;
		upt_steps(game);
		return (0);
	}
	else
		return (1);
}

static int	valid_position_y(t_game *game, char op)
{
	if (op == '+'
		&& game->matrix[game->player_data->y + 1][game->player_data->x] != '1')
	{
		game->player_data->y++;
		game->count_moves++;
		upt_steps(game);
		return (0);
	}
	else if (op == '-'
		&& game->matrix[game->player_data->y - 1][game->player_data->x] != '1')
	{
		game->player_data->y--;
		game->count_moves++;
		upt_steps(game);
		return (0);
	}
	else
		return (1);
}
