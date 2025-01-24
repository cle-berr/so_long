/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:05:19 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:37:10 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	print_length;
	int	base;

	if (format == 'x')
		base = 0;
	else
		base = 1;
	print_length = 0;
	if (format == 'c')
		print_length += ft_print_c(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_s(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_p(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_d_i(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_u(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), base);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	va_start(args, s);
	print_length = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			print_length += ft_formats(args, s[i + 1]);
			i++;
		}
		else
			print_length += ft_print_c(s[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
