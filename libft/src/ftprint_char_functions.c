/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:17:32 by bda-mota          #+#    #+#             */
/*   Updated: 2023/12/13 12:09:15 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen_print(str)));
}

char	*ft_strchr_print(const char *s, int c)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
		return ((char *)(str + i));
	return (NULL);
}

int	ft_strlen_print(char *ptr)
{
	int	count;

	count = 0;
	while (ptr[count] != '\0')
		count++;
	return (count);
}
