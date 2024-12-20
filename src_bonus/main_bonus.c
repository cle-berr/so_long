/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:43 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/20 18:46:03 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	free_img(t_solong *gameinfo)
{
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->coin);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->floor);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->wall);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->player_down);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->player_left);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->player_up);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->player_right);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->exit);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->mob);
}

bool	ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	i -= 4;
	if (argv[i] != '.')
		return (false);
	i++;
	if (argv[i] != 'b')
		return (false);
	i++;
	if (argv[i] != 'e')
		return (false);
	i++;
	if (argv[i] != 'r')
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_solong	gameinfo;
	int			fd;

	if (argc != 2 || !ber(argv[1]))
	{
		error("Argument invalid.");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error("Maps can't be open.");
		return (-1);
	}
	if (!get_map(fd, &gameinfo))
		return (error("Map is invalid"));
	if (!mapcheck(&gameinfo))
	{
		free_maps(gameinfo.map);
		return (-1);
	}
	gameinfo.playermovs = 0;
	create_window(&gameinfo);
	manage_loop(&gameinfo);
	return (0);
}
