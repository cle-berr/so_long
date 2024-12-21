/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skikk <skikk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:47:57 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/21 16:20:24 by skikk            ###   ########.fr       */
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

void	death(t_solong *gameinfo)
{
	gameinfo->playermovs++;
	ft_printf("Your dead with %i movements\n" \
					, gameinfo->playermovs);
	free_img(gameinfo);
	free_maps(gameinfo->map);
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_display(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	death_screen(gameinfo);
}

void	display_move(t_solong *gameinfo, char *msg)
{
	char	*move;

	move = ft_itoa(gameinfo->playermovs);
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		10, 20, 0xFFFFFF, msg);
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, \
		50, 20, 0xFFFFFF, move);
	free(move);
}
