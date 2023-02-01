/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:36:09 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 10:37:09 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	image_window(char **map_arr, t_map *map)
{
	map->y = 0;
	place_floors_walls(map_arr, map);
	while (map->y <= map->y_max)
	{
		map->x = 0;
		while (map_arr[map->y][map->x])
		{
			if (map_arr[map->y][map->x] == 'E')
				mlx_image_to_window(map->mlx, map->exit,
					map->x * 32, map->y * 32);
			if (map_arr[map->y][map->x] == 'C')
				mlx_image_to_window(map->mlx, map->coin,
					map->x * 32, map->y * 32);
			else if ((map->y != 0) && (map->y != map->y_max) && (map->x != 0)
				&& (map->x != (map->x_max - 1))
				&& (map_arr[map->y][map->x] == '1'))
				mlx_image_to_window(map->mlx, map->chest,
					map->x * 32, map->y * 32);
			map->x++;
		}
		map->y++;
	}
	mlx_image_to_window(map->mlx, map->player,
		map->map_player_x * 32, map->map_player_y * 32);
	return ;
}

void	place_floors_walls(char **map_arr, t_map *map)
{
	map->y = 0;
	while (map->y <= map->y_max)
	{
		map->x = 0;
		while (map_arr[map->y][map->x])
		{
			mlx_image_to_window(map->mlx, map->floor, map->x * 32, map->y * 32);
			if ((map->y == 0) || (map->y == map->y_max)
				|| (map->x == 0) || (map->x == (map->x_max - 1)))
				mlx_image_to_window(map->mlx, map->walls,
					map->x * 32, map->y * 32);
			map->x++;
		}
		map->y++;
	}
	map->y = 0;
	map->x = 0;
	return ;
}
