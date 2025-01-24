/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:46:54 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/07 13:49:24 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_print_c(int s);
int	ft_print_d_i(int n);
int	ft_print_percent(void);
int	ft_print_s(char *s);
int	ft_print_u(unsigned int n);
int	ft_print_p(unsigned long long n);
int	ft_print_hex(unsigned int n, int base);

#endif