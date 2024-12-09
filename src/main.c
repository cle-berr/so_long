/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:43 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:59 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

/* void printmap(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
} */
void	free_img(t_solong *gameinfo)
{
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->coin);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->floor);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->wall);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->player);
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->exit);
}

int	main(int argc, char **argv)
{
	t_solong	gameinfo;
	int			fd;

	if (argc != 2)
	{
		ft_printf("Error: number of argument invalid.\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: maps can't be open.\n");
		return (-1);
	}
	get_map(fd, &gameinfo);
	if (!mapcheck(&gameinfo))
	{
		ft_printf("Error: maps is not playable.\n");
		free_maps(gameinfo.map);
		return (-1);
	}
	gameinfo.playermovs = 0;
	create_window(&gameinfo);
	manage_loop(&gameinfo);
	return (0);
}
