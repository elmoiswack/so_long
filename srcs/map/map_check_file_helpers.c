/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:47:03 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 15:02:53 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	copy_variables(t_map *map, t_mapcheck *mpck)
{
	map->map_player_x = mpck->player_x;
	map->map_player_y = mpck->player_y;
	map->c_count = mpck->c_count;
	map->y_max = mpck->y_max;
	map->x_max = mpck->x_max;
	return ;
}

void	map_check_map(t_map *map, t_mapcheck *mpck)
{
	if (map_check_begin(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_check_middle(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_check_end(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_checker_finalcheck(mpck) == -1)
		free_checkers_failed(map, mpck, "\0");
	return ;
}

char	**map_check_final(t_map *map, t_mapcheck *mpck)
{
	map_check_map(map, mpck);
	copy_variables(map, mpck);
	return (map->map);
}
