/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:02:15 by cle-berr          #+#    #+#             */
/*   Updated: 2025/01/24 12:40:30 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	create_imgs(t_solong *gameinfo, int w)
{
	gameinfo->player = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites/isaac.xpm", &w, &w);
	gameinfo->floor = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites/floor.xpm", &w, &w);
	gameinfo->wall = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites/wall.xpm", &w, &w);
	gameinfo->coin = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites/coin.xpm", &w, &w);
	gameinfo->exit = mlx_xpm_file_to_image(gameinfo->mlx_ptr, \
		"sprites/door.xpm", &w, &w);
}

static void	img_parser(t_solong *gameinfo, int x, int y)
{
	mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
	gameinfo->floor, y * 64, x * 64);
	if (gameinfo->map[x][y] == 'P')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->player, y * 64, x * 64);
	else if (gameinfo->map[x][y] == '1')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->wall, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'C')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->coin, y * 64, x * 64);
	else if (gameinfo->map[x][y] == 'E')
		mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		gameinfo->exit, y * 64, x * 64);
}

void	wind_images(t_solong *gameinfo, int side)
{
	int	x;
	int	y;

	(void) side;
	x = 0;
	create_imgs(gameinfo, 64);
	while (x < gameinfo->x)
	{
		y = 0;
		while (y < gameinfo->y)
		{
			img_parser(gameinfo, x, y);
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
}
