/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:18:31 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/22 11:08:49 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[50] = "Hello, World!";
	
	printf("Avant memset : %s\n", str);
	ft_memset(str, '-', 5);
	printf("Après memset : %s\n", str);
	return (0);
}*/
