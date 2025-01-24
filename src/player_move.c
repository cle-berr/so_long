/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:03 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/19 16:36:56 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	finish(t_solong *gameinfo)
{
	if (gameinfo->c_to_get == 0)
	{
		gameinfo->playermovs++;
		ft_printf("Congratulation you won with %i movements\n" \
						, gameinfo->playermovs);
		close_game(gameinfo);
	}
}

void	w_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_x -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->c_to_get--;
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x - 1][gameinfo->pl_y] == 'E')
		finish(gameinfo);
}

void	a_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y -= 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y - 1] == 'E')
		finish(gameinfo);
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
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
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
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x + 1][gameinfo->pl_y] == 'E')
		finish(gameinfo);
}

void	d_movement(t_solong *gameinfo)
{
	if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == '0')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'C')
	{
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = '0';
		gameinfo->pl_y += 1;
		gameinfo->map[gameinfo->pl_x][gameinfo->pl_y] = 'P';
		gameinfo->c_to_get--;
		free_img(gameinfo);
		wind_images(gameinfo, 0);
		gameinfo->playermovs++;
		ft_printf("number of movements: %i\n", gameinfo->playermovs);
	}
	else if (gameinfo->map[gameinfo->pl_x][gameinfo->pl_y + 1] == 'E')
		finish(gameinfo);
}
