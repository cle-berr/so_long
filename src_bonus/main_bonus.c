/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:43 by cle-berr          #+#    #+#             */
/*   Updated: 2025/01/24 11:46:07 by cle-berr         ###   ########.fr       */
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

int	start_fuction(t_solong *gameinfo, int fd, int first)
{
	if (!get_map(fd, gameinfo))
		return (error("Map is invalid"));
	if (!mapcheck(gameinfo))
	{
		free_maps(gameinfo->map);
		return (-1);
	}
	gameinfo->playermovs = 0;
	if (first == 1)
		start_screen(gameinfo);
	else
	{
		create_window(gameinfo);
		manage_loop(gameinfo);
	}
	return (0);
}

void	checkfile(char *arg)
{
	ssize_t	bytes_read;
	char	*map;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(error("maps can't be open."));
	map = malloc(1000);
	if (!map)
		exit(error("memory allocation failed."));
	bytes_read = read(fd, map, 1000 - 1);
	if (bytes_read < 0)
	{
		free(map);
		exit(error("failed to read file."));
	}
	map[bytes_read] = '\0';
	if (bytes_read == 0)
	{
		free(map);
		exit(error("empty file."));
	}
	free(map);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_solong	gameinfo;

	if (argc != 2 || !ber(argv[1]))
	{
		error("Argument invalid.");
		return (-1);
	}
	checkfile(argv[1]);
	gameinfo.fd = open(argv[1], O_RDONLY);
	if (gameinfo.fd == -1)
	{
		error("Maps can't be open.");
		return (-1);
	}
	if (!start_fuction(&gameinfo, gameinfo.fd, 1))
		return (-1);
}
