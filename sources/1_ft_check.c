/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ft_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:19:08 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/08 16:56:30 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_arguments(int argc, char **argv)
{
	if (argc == 1)
		return (error(WARNING_1), (EXIT_FAILURE));
	else if (argc > 2)
		return (error(WARNING_2), (EXIT_FAILURE));
	else if (argc == 2 && check_extension(argv[1]))
		return (error(WARNING_3), (EXIT_FAILURE));
	return (0);
}

int	check_extension(char *filename)
{
	char	*dotber;
	int		i;
	int		len;

	i = 0;
	dotber = ".ber";
	len = ft_strlen(filename);
	len = len - 4;
	while (filename[len] && dotber[i] && filename[len] == dotber[i])
	{
		i++;
		len++;
	}
	if (dotber[i] == '\0')
		return (0);
	else
		return (-1);
}

int	check_invalid_char(t_valid	*map)
{
	if (map->c[0] != 'C' && map->c[0] != 'E' && map->c[0] != 'P'
		&& map->c[0] != '0' && map->c[0] != '\n' && map->c[0] != '1'
		&& map->c[0] != '\0')
		return (1);
	return (0);
}

int	check_content(int fd, t_valid *map)
{
	init_variables_valid(map);
	map->bytes_read = read_file_content(fd, map, 1);
	while (map->bytes_read > 0)
	{
		map->size++;
		if (check_invalid_char(map) == 1)
			map->invalid++;
		else if (map->c[0] == 'C')
			map->collectible++;
		else if (map->c[0] == 'E')
			map->exit++;
		else if (map->c[0] == 'P')
			map->start++;
		else if (map->c[0] == '\n')
			map->n++;
		map->bytes_read = read_file_content(fd, map, 1);
	}
	close(fd);
	if (!check_content_aux(map))
		return (-1);
	return (0);
}

int	check_content_aux(t_valid *map)
{
	if (map->start != 1)
		return (error(WARNING_9), (EXIT_FAILURE));
	else if (map->exit != 1)
		return (error(WARNING_10), (EXIT_FAILURE));
	else if (map->collectible < 1)
		return (error(WARNING_11), (EXIT_FAILURE));
	else if (map->invalid > 0)
		return (error(WARNING_7), (EXIT_FAILURE));
	else if (map->size < 18)
		return (error(WARNING_6), (EXIT_FAILURE));
	return (0);
}
