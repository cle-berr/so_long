/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:30 by cle-berr          #+#    #+#             */
/*   Updated: 2025/01/24 12:49:24 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	get_player_position(t_solong *gameinfo)
{
	int	x;
	int	y;

	x = 0;
	while (x < gameinfo->x)
	{
		y = 0;
		while (y < gameinfo->y)
		{
			if (gameinfo->map[x][y] == 'P')
			{
				gameinfo->pl_x = x;
				gameinfo->pl_y = y;
				break ;
			}
			y++;
		}
		x++;
	}
}

void	verif_map(t_solong *gameinfo, char *line)
{
	unsigned long	i;

	i = 1;
	if (gameinfo->x > 15 || gameinfo->y > 30)
	{
		free(line);
		exit(error("Map must be smaller to be playable."));
	}
	while (i != ft_strlen(line) - 1)
	{
		if (line[i - 1] == '\n' && line[i] == '\n')
		{
			free(line);
			exit(error("Multiple '\\n' find in map."));
		}
		i++;
	}
}

int	get_map(int fd, t_solong *gameinfo)
{
	char	*line;
	char	*new_line;
	char	*tmp_line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	gameinfo->y = ft_strlen(line) - 1;
	gameinfo->x = 1;
	new_line = get_next_line(fd);
	while (new_line)
	{
		tmp_line = ft_strjoin(line, new_line);
		free(line);
		free(new_line);
		line = tmp_line;
		new_line = get_next_line(fd);
		gameinfo->x++;
	}
	verif_map(gameinfo, line);
	gameinfo->map = ft_split(line, '\n');
	free(line);
	get_player_position(gameinfo);
	return (1);
}
