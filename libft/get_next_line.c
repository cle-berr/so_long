/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:40:45 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/05 11:04:03 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*store_line(int fd, char *stored)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*temp;

	if (!stored)
		stored = ftstrdup("");
	while (!ftstrchr(stored, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (stored)
				free(stored);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = stored;
		stored = ftstrjoin(temp, buffer);
		free(temp);
		if (!stored)
			return (NULL);
	}
	return (stored);
}

char	*save_next(char *stored)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	save = (char *)malloc(ftstrlen(stored) - i + 1);
	if (!save)
		return (NULL);
	i++;
	j = 0;
	while (stored[i])
		save[j++] = stored[i++];
	save[j] = '\0';
	free(stored);
	return (save);
}

char	*ft_get_line(char *stored)
{
	int		len;
	char	*line;

	len = 0;
	while (stored[len] && stored[len] != '\n')
		len++;
	line = (char *)malloc(len + (stored[len] == '\n') + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (stored[len] && stored[len] != '\n')
	{
		line[len] = stored[len];
		len++;
	}
	if (stored[len] == '\n')
	{
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = store_line(fd, stored);
	if (!stored || *stored == '\0')
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	line = ft_get_line(stored);
	stored = save_next(stored);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	int i = 5;

// 	fd = open("test2.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 		i--;
// 	}
// 	close(fd);
// 	return (0);
// }
