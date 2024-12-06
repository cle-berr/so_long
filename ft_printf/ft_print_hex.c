/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:19:40 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:36:55 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_recursive(unsigned int n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += hex_recursive(n / 16, hex);
		count += ft_print_c(hex[n % 16]);
	}
	else
		count += ft_print_c(hex[n % 16]);
	return (count);
}

int	ft_print_hex(unsigned int n, int base)
{
	char	*hex;

	if (base)
		hex = "0123456789ABCDEFG";
	else
		hex = "0123456789abcdefg";
	if (n == 0)
		return (ft_print_c('0'));
	else
		return (hex_recursive(n, hex));
}
