/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:36:09 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/20 19:08:13 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	image_window(t_image *image, char **map_arr, t_map *map, t_mapcheck *mpck)
{
	map->y = 0;
	place_floors_walls(image, map_arr, map, mpck);
	while (map->y <= mpck->y_max)
	{
		map->x = 0;
		while (map_arr[map->y][map->x])
		{
			if (map_arr[map->y][map->x] == 'P')
				mlx_image_to_window(map->mlx, image->player, map->x * 31, map->y * 31);
			if (map_arr[map->y][map->x] == 'E')
				mlx_image_to_window(map->mlx, image->exit, map->x * 31, map->y * 31);
			if (map_arr[map->y][map->x] == 'C')
				mlx_image_to_window(map->mlx, image->coin, map->x * 31, map->y * 31);
			else if ((map->y != 0) && (map->y != mpck->y_max) && (map->x != 0) && (map->x != (mpck->x_max - 1))&& (map_arr[map->y][map->x] == '1'))
				mlx_image_to_window(map->mlx, image->chest, map->x * 31, map->y * 31);
			map->x++;
		}
		map->y++;
	}
	return ;
}

void	place_floors_walls(t_image *image, char **map_arr, t_map *map, t_mapcheck *mpck)
{
	map->y = 0;
	while (map->y <= mpck->y_max)
	{
		map->x = 0;
		while (map_arr[map->y][map->x])
		{
			mlx_image_to_window(map->mlx, image->floor, map->x * 31, map->y * 31);
			if ((map->y == 0) || (map->y == mpck->y_max) || (map->x == 0) || (map->x == (mpck->x_max - 1)))
				mlx_image_to_window(map->mlx, image->walls, map->x * 31, map->y * 31);
			map->x++;
		}
		map->y++;
	}
	map->y = 0;
	map->x = 0;
	return ;
}