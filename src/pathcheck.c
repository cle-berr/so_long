/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:36:12 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/06 18:06:55 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void map_copy(t_solong *gameinfo, char **copy)
{
    int i;

    i = 0;
    while (i < gameinfo->x)
    {
        copy[i] = ft_substr(gameinfo->map[i], 0, ft_strlen(gameinfo->map[i]));
        if (!copy[i])
        {
            free_maps(copy);
            copy[0] = NULL;
            return;
        }
        i++;
    }
    copy[i] = NULL;
}

static void flood_fill(char **map, int x, int y, int *valid)
{
    if (y < 0 || !map || !map[y] || x < 0 || x >= (int)ft_strlen(map[y]))
        return;
    if (map[y][x] == '1' || map[y][x] == 'V')
        return;
    if (map[y][x] == 'C' || map[y][x] == 'E')
        (*valid)--;
    map[y][x] = 'V';
    flood_fill(map, x + 1, y, valid);
    flood_fill(map, x - 1, y, valid);
    flood_fill(map, x, y + 1, valid);
    flood_fill(map, x, y - 1, valid);
}

bool check_path(t_solong *gameinfo)
{
    int valid;
    char **copy_map;

    valid = gameinfo->ecount + gameinfo->c_to_get;
    copy_map = (char **)(ft_calloc(gameinfo->x + 1, sizeof(char *)));
    if (!copy_map)
        return (false);
    map_copy(gameinfo, copy_map);
    if (!copy_map[0])
    {
        free(copy_map);
        return (false);
    }
    flood_fill(copy_map, gameinfo->pl_x, gameinfo->pl_y, &valid);
    free_maps(copy_map);
    if (valid != 0)
        return (false);
    return (true);
}


