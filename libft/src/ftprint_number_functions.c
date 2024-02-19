/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:18:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/01/03 10:02:48 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_print_int(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	n = n % 10 + '0';
	count += ft_print_char(n);
	return (count);
}
