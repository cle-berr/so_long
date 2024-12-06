/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:48:14 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/21 10:52:04 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_forward(unsigned char *dest, const unsigned char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int						i;
	unsigned char			*strdest;
	const unsigned char		*strsrc;

	if (!src && !dest)
		return (NULL);
	i = n - 1;
	strsrc = src;
	strdest = dest;
	if (strsrc < strdest)
	{
		while (i >= 0)
		{
			strdest[i] = strsrc[i];
			i--;
		}
	}
	else
		copy_forward(strdest, strsrc, (int)n);
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "abcdefghij";
	char str2[] = "abcdefghij";
	ft_memmove(str1 + 2, str1 + 3, 3);
	printf("%s\n", str1);
	memmove(str2 + 2, str2 + 3, 3);
	printf("%s\n", str2);
	return 0;
}*/