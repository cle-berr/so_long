/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:26:12 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/16 13:14:14 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	y;
	size_t	res;

	c = 0;
	y = 0;
	res = 0;
	while (dst[c] != '\0')
		c++;
	while (src[res] != '\0')
		res++;
	if (size <= c)
		res += size;
	else
		res += c;
	while (src[y] != '\0' && (c + 1) < size)
	{
		dst[c] = src[y];
		c++;
		y++;
	}
	dst[c] = '\0';
	return (res);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    char dst[20] = "Hello";
    char src[] = ", World!";

    printf("Length: %zu\n", ft_strlcat(dst, src, 5)); 

    return 0;
}*/