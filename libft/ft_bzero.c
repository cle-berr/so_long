/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:08:03 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/22 10:04:38 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

/*#include <stdio.h>

int main() {
    char str[15] = "Hello, World!";
    
    printf("Avant: %s\n", str);
    ft_bzero(str, 2);
    printf("Après: %s\n", str);
    
    return 0;
}*/