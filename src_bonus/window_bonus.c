/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:15 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/19 17:09:05 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	create_imgs(t_solong *gameinfo, int w)
{
	gameinfo->player_down = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/isaac_down.xpm", &w, &w);
	gameinfo->player_up = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/isaac_up.xpm", &w, &w);
	gameinfo->player_left = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/isaac_left.xpm", &w, &w);
	gameinfo->player_right = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/isaac_right.xpm", &w, &w);
	gameinfo->floor = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/floor.xpm", &w, &w);
	gameinfo->wall = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/wall.xpm", &w, &w);
	gameinfo->coin = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/coin.xpm", &w, &w);
	gameinfo->exit = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/door.xpm", &w, &w);
	gameinfo->mob = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites_bonus/monster.xpm", &w, &w);
}

static void	player_parser(t_solong *gameinfo, int x, int y, int side)
{
	if (gameinfo->map[x][y] == 'P' && side == 0)
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->player_down, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'P' && side == 1)
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->player_up, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'P' && side == 2)
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->player_left, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'P' && side == 3)
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->player_right, y * 64, x * 64);
}

static void	img_parser(t_solong *gameinfo, int x, int y, int side)
{
	mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
	gameinfo->floor, y * 64, x * 64);
	if (gameinfo->map[x][y] == 'P')
		player_parser(gameinfo, x, y, side);
	else if (gameinfo->map[x][y] == '1')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->wall, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'C')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->coin, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'E')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->exit, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'M')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->mob, y * 64, x * 64);
}

void	wind_images(t_solong *gameinfo, int side)
{
	int	x;
	int	y;

	x = 0;
	create_imgs(gameinfo, 64);
	while (x < gameinfo->x)
	{
		y = 0;
		while (y < gameinfo->y)
		{
			img_parser(gameinfo, x, y, side);
			y++;
		}
		x++;
	}
}

void	create_window(t_solong *gameinfo)
{
	gameinfo->mlx_ptr = mlx_init();
	gameinfo->window_ptr = mlx_new_window(gameinfo->mlx_ptr, \
	gameinfo->y * 64, gameinfo->x * 64, "So Long");
	wind_images(gameinfo, 0);
	display_move(gameinfo, "Move :");
}
