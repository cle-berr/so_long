/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:41 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/21 10:51:45 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	n1;
	int		len;

	n1 = n;
	len = int_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n1 = -n1;
	}
	while (len > 0 && n1 > 0)
	{
		res[--len] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (res);
}

/*#include <stdio.h>

int main()
{
	char *res = ft_itoa(-2147483648);
	printf("%s\n", res);
    free(res);
	
}*/