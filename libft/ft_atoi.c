/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:06:49 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/18 11:37:52 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

/*#include <stdio.h>

int main()
{
	
	printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
	//printf("%d\n", ft_atoi("---7768sbsdh"));
	//printf("%d\n", ft_atoi("-57358fjsd"));
	//printf("%d\n", ft_atoi("+42lehavre"));
	printf("%d\n", atoi("\t\n\r\v\f  469 \n"));
	//printf("%d\n", atoi("---7768sbsdh"));
	//printf("%d\n", atoi("-57358fjsd"));
}*/