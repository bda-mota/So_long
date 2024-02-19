/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:53:24 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/19 18:46:51 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	build_matrix(int fd, t_game *game)
{
	int		bytes;

	game->content = ft_strdup("");
	bytes = read(fd, game->buffer, 10);
	while (bytes > 0)
	{
		game->buffer[bytes] = '\0';
		game->aux = ft_strjoin(game->content, game->buffer);
		free(game->content);
		game->content = game->aux;
		bytes = read(fd, game->buffer, 10);
	}
	if (bytes == -1)
		return (error(WARNING_16), (EXIT_FAILURE));
	game->matrix = ft_split(game->content, '\n');
	game->clone = ft_split(game->content, '\n');
	free(game->content);
	return (0);
}

int	is_rectangle(t_game *game, t_valid *map)
{
	size_t	i;

	i = 0;
	game->cols = ft_strlen(game->matrix[0]);
	while (game->matrix[i])
	{
		if (game->cols != ft_strlen(game->matrix[i]))
		{
			free_matrices(game);
			return (error(WARNING_8), (EXIT_FAILURE));
		}
		game->rows++;
		i++;
	}
	if (map->n > (game->rows))
	{
		free_matrices(game);
		return (error(WARNING_15), (EXIT_FAILURE));
	}
	return (0);
}

int	surrounded_by_walls(t_game *game)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	while (++i < game->rows)
	{
		if (game->matrix[i][0] != '1'
			|| (game->matrix[i][game->cols - 1] != '1'))
		{
			free_matrices(game);
			return (error(WARNING_12), (EXIT_FAILURE));
		}
	}
	while (++j < game->cols)
	{
		if (game->matrix[0][j] != '1'
			|| (game->matrix[game->rows - 1][j] != '1'))
		{
			free_matrices(game);
			return (error(WARNING_12), (EXIT_FAILURE));
		}
	}
	return (0);
}

void	free_matrix(char **matrix_delete)
{
	int		i;

	i = 0;
	while (matrix_delete[i] != NULL)
	{
		free(matrix_delete[i]);
		i++;
	}
	free(matrix_delete);
}

void	free_matrices(t_game *game)
{
	free_matrix(game->matrix);
	free_matrix(game->clone);
}
