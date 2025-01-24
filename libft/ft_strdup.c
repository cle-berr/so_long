/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:48:22 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/09 10:48:35 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

/*#include <stdio.h>

int main(void)
{
	char *str = "bonjour";
	char *copy = ft_strdup(str);
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != copy[i])
			printf("%s", "faux");
		i++;
	}
	printf("%s\n", str);
	printf("%s", copy);
	
	free(copy);
}*/