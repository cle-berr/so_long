/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:15:12 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/21 10:53:20 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_in(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (s1[i] && set_in(s1[i], set))
		i++;
	while (len > i && set_in(s1[len - 1], set))
		len--;
	res = (char *)malloc(sizeof(char) * ((len - i) + 1));
	if (!res)
		return (NULL);
	while (i != len)
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

/*#include <stdio.h>

int main()
{
	char const *s1 = "ouoouiuuiuiuoioiuiuoiuuouiuoiuoiuouiouiouioi";
	char const *set = "oiu";

	printf("%s\n", ft_strtrim(s1, set));
}*/