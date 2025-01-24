/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:16:41 by cle-berr          #+#    #+#             */
/*   Updated: 2024/10/22 11:11:09 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, size_t len)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	copy_word(char **res, const char *s, int *i, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	res[*i] = ft_strndup(s, len);
	if (!res[*i])
	{
		while ((*i)-- > 0)
			free(res[*i]);
		free(res);
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	res = ft_calloc(word + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!copy_word(res, s, &i, c))
				return (NULL);
			s += ft_strlen(res[i - 1]);
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

/*

//to test fonction count word

#include <stdio.h>

int main()
{
	char *src = "";
	char sep = ' ';
	int res;

	res = count_word(src, sep);
	printf("nbr wrd : %d\n", res);
}*/

/*#include <stdio.h>

int main(void)
{
	char **result;
	int i;

	result = ft_split("split de *\;'#@* qui ma saouler des heures 	", ' ');
	i = 0;
	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return 0;
}*/
