/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:03 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/19 17:01:06 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	w_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 1);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 1);
		gameinfo->c_to_get--;
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'E')
		finish(gameinfo);
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'M')
		death(gameinfo);
}

void	a_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 2);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		free_img(gameinfo);
		wind_images(gameinfo, 2);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'E')
		finish(gameinfo);
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'M')
		death(gameinfo);
}

void	s_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'E')
		finish(gameinfo);
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'M')
		death(gameinfo);
}

void	d_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 3);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		free_img(gameinfo);
		wind_images(gameinfo, 3);
		gameinfo->playermovs++;
		display_move(gameinfo, "Move :");
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'E')
		finish(gameinfo);
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'M')
		death(gameinfo);
}
