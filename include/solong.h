/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:48:53 by ealgar-c          #+#    #+#             */
/*   Updated: 2025/01/08 14:09:14 by cle-berr         ###   ########.fr       */
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
	void	*player_down;
	void	*player_right;
	void	*player_up;
	void	*player_left;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
	void	*mob;
	void	*startscreen;
	void	*deathscreen;
	char	**map;
	int		fd;
	int		x;
	int		y;
	int		pl_x;
	int		pl_y;
	int		c_to_get;
	int		playermovs;
	int		ecount;
	int		acc_e;
}	t_solong;

bool	other_charac(int x, int y, t_solong *gameinfo);
int		get_map(int fd, t_solong *gameinfo);
void	create_window(t_solong *gameinfo);
void	manage_loop(t_solong *gameinfo);
void	wind_images(t_solong *gameinfo, int side);
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
bool	error(char *msg);
void	death(t_solong *gameinfo);
void	finish(t_solong *gameinfo);
void	display_move(t_solong *gameinfo, char *msg);
void	start_screen(t_solong *gameinfo);
void	death_screen(t_solong *gameinfo);
int		start_fuction(t_solong *gameinfo, int fd, int first);

#endif