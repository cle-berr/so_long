/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:12:10 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:35:51 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_recursive(unsigned long long n, char *hex)
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

static int	ft_print_x(unsigned long long n)
{
	char	*hex;

	hex = "0123456789abcdefg";
	if (n == 0)
		return (ft_print_c('0'));
	else
		return (hex_recursive(n, hex));
}

int	ft_print_p(unsigned long long n)
{
	int	count;

	if (n == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_print_x(n);
	return (count);
}
