/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:17:53 by bda-mota          #+#    #+#             */
/*   Updated: 2023/12/13 11:03:37 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_arg(const char ptr, va_list arg)
{
	int	count;

	count = 0;
	if (ptr == 'i' || ptr == 'd')
		count = ft_print_int(va_arg(arg, int));
	else if (ptr == 'c')
		count = ft_print_char(va_arg(arg, int));
	else if (ptr == 's')
		count = ft_print_string(va_arg(arg, char *));
	else if (ptr == 'u')
		count = ft_print_unsigned(va_arg(arg, unsigned int));
	else if (ptr == 'x')
		count = ft_print_lower_hex(va_arg(arg, int));
	else if (ptr == 'X')
		count = ft_print_upper_hex(va_arg(arg, int));
	else if (ptr == '%')
		count = write(1, "%", 1);
	else if (ptr == 'p')
		count = ft_print_address(va_arg(arg, unsigned long));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		value;

	if (!str)
		return (-1);
	va_start(arg, str);
	i = 0;
	value = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr_print("cdiusxXp%", str[i + 1]))
		{
			i++;
			value += ft_check_arg(str[i], arg);
		}
		else
			value += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (value);
}
