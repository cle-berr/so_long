/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:56:40 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/20 18:43:16 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	display_start_screen(t_solong *gameinfo)
{
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 50, 50, \
		0xFFFFFF, "Welcome to So_Long!");
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 50, 80, \
		0xFFFFFF, "Press W to start the game.");
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 50, 110, \
		0xFFFFFF, "Press ESC or click X to quit.");
}

int	close_start_screen(t_solong *gameinfo)
{
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_display(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	return (0);
}

int	start_screen_keypress(int keycode, t_solong *gameinfo)
{
	if (keycode == W_KEY)
	{
		close_start_screen(gameinfo);
		create_window(gameinfo);
		manage_loop(gameinfo);
	}
	else if (keycode == ESCAPE_KEY)
	{
		close_start_screen(gameinfo);
	}
	return (0);
}

void	start_screen(t_solong *gameinfo)
{
	gameinfo->mlx_ptr = mlx_init();
	gameinfo->window_ptr = mlx_new_window(gameinfo->mlx_ptr, 640, 480, \
		"Welcome to So_Long");
	display_start_screen(gameinfo);
	mlx_key_hook(gameinfo->window_ptr, start_screen_keypress, gameinfo);
	mlx_hook(gameinfo->window_ptr, 17, 0, close_start_screen, gameinfo);
	mlx_loop(gameinfo->mlx_ptr);
}
