/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:40:50 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/18 10:06:36 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	i = 0;
	while (i < len && big[i])
	{
		if (i + little_len > len)
			return (NULL);
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len && little[j])
			j++;
		if (j == little_len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int main() 
{
	char big[] = "loutre";
	char little[] = "ut";
	printf("rendu :%s\n",ft_strnstr(big, little, 3));
	return 0;
}*/