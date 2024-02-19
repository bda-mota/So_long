/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:14:21 by bda-mota          #+#    #+#             */
/*   Updated: 2024/01/23 13:29:50 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read_file_bonus(int fd, t_find *file, t_gnl **root)
{
	file->bytes = read(fd, file->buffer, BUFFER_SIZE);
	if (file->bytes < 0)
	{
		ft_dealloc(root);
		return (0);
	}
	if (file->bytes == 0)
		return (1);
	file->buffer[file->bytes] = '\0';
	return (2);
}

char	*get_next_line_bonus(int fd)
{
	static t_find	f[1026];
	int				len;
	int				verify;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1026)
		return (NULL);
	f[fd].str = NULL;
	len = 0;
	while (ft_lstchr_bonus(f[fd].str) == 0)
	{
		if (f[fd].pos > 0 && f[fd].pos != f[fd].bytes && f[fd].bytes != 0)
		{
			len += ft_build_line_bonus(&f[fd], &f[fd].str, f[fd].bytes);
			continue ;
		}
		verify = ft_read_file_bonus(fd, &f[fd], &f[fd].str);
		if (verify == 0)
			return (NULL);
		if (verify == 1)
			break ;
		len += ft_build_line_bonus(&f[fd], &f[fd].str, f[fd].bytes);
	}
	return (ft_transform_bonus(f[fd].str, len));
}
