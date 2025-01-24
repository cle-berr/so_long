/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:32:07 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/18 09:59:56 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main() 
{
	const char *str = "Hello, World!";
	char ch = 'l';

	printf("ft_strchr: trouvé à la position : %s\n", ft_strrchr(str, ch));

	printf("strchr: trouvé à la position : %s\n", strrchr(str, ch));

	return 0;
}*/
