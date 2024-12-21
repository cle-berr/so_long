#include "../include/solong.h"

void	display_death_screen(t_solong *gameinfo)
{
	int	i;
	int	j;

	i = 388;
	j = 130;
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 250, 250, \
		0xFFFFFF, "Welcome to So_Long!");
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 230, 280, \
		0xFFFFFF, "Press W to restart the game.");
	mlx_string_put(gameinfo->mlx_ptr, gameinfo->window_ptr, 220, 310, \
		0xFFFFFF, "Press ESC or click X to quit.");
	gameinfo->startscreen = mlx_xpm_file_to_image(gameinfo->mlx_ptr, "sprites_bonus/startscreen.xpm", &i, &j);
	mlx_put_image_to_window(gameinfo->mlx_ptr, gameinfo->window_ptr, gameinfo->startscreen, 110, 80);
}

int	close_death_screen(t_solong *gameinfo)
{
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->startscreen);
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_display(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	close_to_restart(t_solong *gameinfo)
{
	mlx_destroy_image(gameinfo->mlx_ptr, gameinfo->startscreen);
	mlx_clear_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_window(gameinfo->mlx_ptr, gameinfo->window_ptr);
	mlx_destroy_display(gameinfo->mlx_ptr);
	free(gameinfo->mlx_ptr);
	return (0);
}

int	death_screen_keypress(int keycode, t_solong *gameinfo)
{
	if (keycode == W_KEY)
	{
		close_to_restart(gameinfo);
		start_fuction(gameinfo, gameinfo->fd, 0);
	}
	else if (keycode == ESCAPE_KEY)
		close_death_screen(gameinfo);
	return (0);
}

void	death_screen(t_solong *gameinfo)
{
	gameinfo->mlx_ptr = mlx_init();
	gameinfo->window_ptr = mlx_new_window(gameinfo->mlx_ptr, 640, 480, \
		"Welcome to So_Long");
	display_death_screen(gameinfo);
	mlx_key_hook(gameinfo->window_ptr, death_screen_keypress, gameinfo);
	mlx_hook(gameinfo->window_ptr, 17, 0, close_death_screen, gameinfo);
	mlx_loop(gameinfo->mlx_ptr);
}