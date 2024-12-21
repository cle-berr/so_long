/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skikk <skikk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:37 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/21 15:21:55 by skikk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static bool	check_shape(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = gameinfo->x - 1;
	while (i_aux >= 0)
	{
		if (ftstrlen(gameinfo->map[i_aux]) != gameinfo->y)
			return (false);
		i_aux--;
	}
	return (true);
}

static bool	check_count(t_solong *gameinfo)
{
	int	pcount;
	int	x;
	int	y;

	pcount = 0;
	gameinfo->ecount = 0;
	gameinfo->c_to_get = 0;
	x = -1;
	while (++x < gameinfo->x)
	{
		y = -1;
		while (++y < gameinfo->y)
		{
			if (gameinfo->map[x][y] == 'P')
				pcount++;
			else if (gameinfo->map[x][y] == 'C')
				gameinfo->c_to_get++;
			else if (gameinfo->map[x][y] == 'E')
				gameinfo->ecount++;
		}
	}
	if (pcount == 1 && gameinfo->ecount == 1 && (gameinfo->c_to_get >= 1))
		return (true);
	return (false);
}

static bool	check_char(t_solong *gameinfo)
{
	int	x;
	int	y;

	x = -1;
	while (++x < gameinfo->x)
	{
		y = -1;
		while (++y < gameinfo->y)
		{
			if (!other_charac(x, y, gameinfo))
				return (false);
		}
	}
	return (true);
}

bool	mapcheck(t_solong *gameinfo)
{
	if (!check_shape(gameinfo))
		return (error("Invalid shape."));
	if (!check_walls(gameinfo))
		return (error("Side walls must be '1'."));
	if (!check_count(gameinfo))
		return (error("Invalid count of 'P', 'E', or 'C'."));
	if (!check_path(gameinfo))
		return (error("Map is not playable."));
	if (!check_char(gameinfo))
		return (error("Map must contain only authorized characters."));
	return (true);
}
