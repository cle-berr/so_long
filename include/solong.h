/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:53 by ealgar-c          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:11 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define ESCAPE_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

typedef struct s_solong
{
	void	*mlx_ptr;
	void	*window_ptr;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	char	**map;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		c_to_get;
	int		playermovs;
	int		ecount;
	int		acc_e;
}	t_solong;

void	get_map(int fd, t_solong *gameinfo);
void	create_window(t_solong *gameinfo);
void	manage_loop(t_solong *gameinfo);
void	wind_images(t_solong *gameinfo);
void	w_movement(t_solong *gameinfo);
void	a_movement(t_solong *gameinfo);
void	s_movement(t_solong *gameinfo);
void	d_movement(t_solong *gameinfo);
bool	mapcheck(t_solong *gameinfo);
bool	check_walls(t_solong *gameinfo);
bool	check_path(t_solong *gameinfo);
int		close_game(t_solong *gameinfo);
void	free_maps(char **map);
void	free_img(t_solong *gameinfo);

#endif