/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:28:24 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/22 10:35:46 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (const unsigned char *)s;

	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdef";
	char str2[] = "abcdef";

	printf("%s\n", (char *)ft_memchr(str1, 'd', 4));
	printf("%s\n", (char *)memchr(str2, 'd', 4));
}*/