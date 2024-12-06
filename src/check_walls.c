/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:37:01 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/06 16:57:48 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static bool	top_row(t_solong *gameinfo)
{
	int	j_aux;

	j_aux = 0;
	while (j_aux < gameinfo->y)
	{
		if (gameinfo->map[0][j_aux] == '1')
			j_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	bot_row(t_solong *gameinfo)
{
	int	j_aux;

	j_aux = 0;
	while (j_aux < gameinfo->y)
	{
		if (gameinfo->map[gameinfo->x - 1][j_aux] == '1')
			j_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	first_col(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = 0;
	while (i_aux < gameinfo->x)
	{
		if (gameinfo->map[i_aux][0] == '1')
			i_aux++;
		else
			return (false);
	}
	return (true);
}

static bool	last_col(t_solong *gameinfo)
{
	int	i_aux;

	i_aux = 0;
	while (i_aux < gameinfo->x)
	{
		if (gameinfo->map[i_aux][gameinfo->y - 1] == '1')
			i_aux++;
		else
			return (false);
	}
	return (true);
}

bool	check_walls(t_solong *gameinfo)
{
	if (top_row(gameinfo))
		if (bot_row(gameinfo))
			if (first_col(gameinfo))
				if (last_col(gameinfo))
					return (true);
	return (false);
}
