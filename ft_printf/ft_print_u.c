/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:53:09 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:39:29 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_d_i (n / 10);
	count += ft_print_c ('0' + (n % 10));
	return (count);
}
