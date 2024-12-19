/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:30 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/19 15:08:54 by cle-berr         ###   ########.fr       */
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
	if (gameinfo->x > 15 || gameinfo->y > 30)
	{
		free(line);
		exit(error("Map must be smaller to be playable."));
	}
	if (line[ft_strlen(line) - 1] == '\n' && line[ft_strlen(line) - 2] == '\n')
	{
		free(line);
		exit(error("Multiple '\\n' find in map."));
	}
}

void	get_map(int fd, t_solong *gameinfo)
{
	char	*line;
	char	*new_line;
	char	*tmp_line;

	line = get_next_line(fd);
	if (!line)
		return ;
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
}
