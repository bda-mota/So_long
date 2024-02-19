/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_flood_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:32:08 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/08 18:37:40 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	flood_fill_aux(t_game *game, size_t row, size_t col)
{
	if (row < 1 || row > game->rows || col < 1 || col > game->cols
		|| game->clone[row][col] == '1' || game->clone[row][col] == 'X')
		return ;
	game->clone[row][col] = '1';
	flood_fill_aux(game, row - 1, col);
	flood_fill_aux(game, row + 1, col);
	flood_fill_aux(game, row, col - 1);
	flood_fill_aux(game, row, col + 1);
}

void	flood_fill(t_game *game)
{
	int	row;
	int	col;

	col = 0;
	while (game->clone[col] != NULL)
	{
		row = 0;
		while (game->clone[col][row] != '\0')
		{
			if (game->clone[col][row] == 'P')
			{
				game->player_x = row;
				game->player_y = col;
				flood_fill_aux(game, col, row);
				if (!check_clone_content(game))
					game->flag++;
				break ;
			}
			row++;
		}
		col++;
	}
	free_matrix(game->clone);
}

int	check_clone_content(t_game *game)
{
	int	i;
	int	j;
	int	missing;

	i = 0;
	missing = 0;
	while (game->clone[i])
	{
		j = 0;
		while (game->clone[i][j])
		{
			if (game->clone[i][j] == 'C' || game->clone[i][j] == 'E')
				missing++;
			j++;
		}
		i++;
	}
	if (missing != 0)
		return (0);
	return (1);
}
