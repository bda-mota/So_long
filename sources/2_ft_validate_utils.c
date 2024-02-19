/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_ft_validate_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:46:46 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/15 11:59:40 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

int	read_file_content(int fd, t_valid *map, int bytes)
{
	int		content;

	content = read(fd, map->c, bytes);
	if (content == -1)
		return (error(WARNING_14), (EXIT_FAILURE));
	else if (content == 0)
		return (0);
	return (content);
}

void	error(char *str)
{
	int	x;

	x = 0;
	while (*str)
		x += (int)write(1, str++, 1);
}

void	ft_error(t_game *game)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	hook_close(game);
	exit(EXIT_FAILURE);
}
