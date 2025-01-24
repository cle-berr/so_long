/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:12 by cle-berr          #+#    #+#             */
/*   Updated: 2025/01/24 13:24:46 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	map_copy(t_solong *gameinfo, char **copy)
{
	int	i;

	i = 0;
	while (i < gameinfo->x)
	{
		copy[i] = ft_substr(gameinfo->map[i], 0, ft_strlen(gameinfo->map[i]));
		if (!copy[i])
		{
			free_maps(copy);
			copy[0] = NULL;
			return ;
		}
		i++;
	}
	copy[i] = NULL;
}

int	getinfo(t_solong *gameinfo, int c, int e)
{
	int	result;

	result = gameinfo->c_to_get + gameinfo->ecount;
	gameinfo->c_to_get = c;
	gameinfo->ecount = e;
	return (result);
}

static void	flood_fill(char **map, int x, int y, t_solong *gameinfo)
{
	if (map[x][y] == '1' || map[x][y] == 'M' || map[x][y] == 'V')
		return ;
	if (map [x][y] == 'E' && gameinfo->ecount > 0)
	{
		map[x][y] = 'V';
		gameinfo->ecount--;
		return ;
	}
	if (map[x][y] == 'C')
		gameinfo->c_to_get--;
	map[x][y] = 'V';
	flood_fill(map, x + 1, y, gameinfo);
	flood_fill(map, x - 1, y, gameinfo);
	flood_fill(map, x, y + 1, gameinfo);
	flood_fill(map, x, y - 1, gameinfo);
}

bool	check_path(t_solong *gameinfo)
{
	int		c;
	char	**copy_map;
	int		e;

	e = gameinfo->ecount;
	c = gameinfo->c_to_get;
	copy_map = (char **)(ft_calloc(gameinfo->x + 1, sizeof(char *)));
	if (!copy_map)
		return (false);
	map_copy(gameinfo, copy_map);
	if (!copy_map[0])
	{
		free(copy_map);
		return (false);
	}
	flood_fill(copy_map, gameinfo->pl_x, gameinfo->pl_y, gameinfo);
	free_maps(copy_map);
	if (getinfo(gameinfo, c, e))
		return (false);
	return (true);
}
