/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:54:20 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/05 12:51:42 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	result = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i != (int)ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j != (int)ft_strlen(s2))
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*#include <stdio.h>

int main()
{
	char	*s1 = "coucou";
	char	*s2 = ", sa va toi ?";

	printf("%s\n", ft_strjoin(s1, s2));
}*/