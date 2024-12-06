/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:12:05 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:38:39 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d_i(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else
	{
		if (n < 0)
		{
			ft_print_c('-');
			n = -n;
			count++;
		}
		if (n >= 10)
			count += ft_print_d_i (n / 10);
		count += ft_print_c ('0' + (n % 10));
	}
	return (count);
}

/* int main()
{
	int n;
	
	n = -1213;
	ft_print_d_i(n);
} */
