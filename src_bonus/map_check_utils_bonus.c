/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:59 by cle-berr          #+#    #+#             */
/*   Updated: 2025/01/08 11:15:16 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

bool	error(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	return (false);
}

bool	other_charac(int x, int y, t_solong *gameinfo)
{
	if (gameinfo->map[x][y] == 'P')
		return (true);
	if (gameinfo->map[x][y] == 'E')
		return (true);
	if (gameinfo->map[x][y] == '1')
		return (true);
	if (gameinfo->map[x][y] == '0')
		return (true);
	if (gameinfo->map[x][y] == 'C')
		return (true);
	if (gameinfo->map[x][y] == 'M')
		return (true);
	return (false);
}
