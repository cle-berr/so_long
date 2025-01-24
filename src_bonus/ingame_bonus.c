/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ingame.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:53 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/18 17:20:39 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	free_maps(char **map)
{
	char	**ptr;

	if (!map)
		return ;
	ptr = map;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(map);
}

int	close_game(t_solong *gameinfo)
{
	free_img(gameinfo);
	free_maps(gameinfo->map);
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_display(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	moveplayer(int keycode, t_solong *gameinfo)
{
	if (keycode == W_KEY)
		w_movement(gameinfo);
	if (keycode == A_KEY)
		a_movement(gameinfo);
	if (keycode == S_KEY)
		s_movement(gameinfo);
	if (keycode == D_KEY)
		d_movement(gameinfo);
}

static int	key_handler(int keycode, t_solong *gameinfo)
{
	if (keycode == ESCAPE_KEY)
		close_game(gameinfo);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
		moveplayer(keycode, gameinfo);
	return (0);
}

void	manage_loop(t_solong *gameinfo)
{
	mlx_key_hook(gameinfo->window_ptr, key_handler, gameinfo);
	mlx_hook(gameinfo->window_ptr, 17, 0, close_game, gameinfo);
	mlx_loop(gameinfo->mlx_ptr);
}
