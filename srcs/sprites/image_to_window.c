/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:36:09 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/18 15:50:42 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	image_window(t_image *image, char **map_arr, t_map *map, t_mapcheck *mpck)
{
	map->y = 0;
	while (map->y <= mpck->y_max)
	{
		map->x = 0;
		while (map_arr[map->y][map->x])
		{
			//image_window_border(image, map);
			// if (map_arr[map->y][map->x] == 'P')
			// 	mlx_image_to_window(map->mlx, image->player, map->x, map->y);
			// else if (map_arr[map->y][map->x] == 'E')
			// 	mlx_image_to_window(map->mlx, image->exit, map->x, map->y);
			if (map_arr[map->y][map->x] == 'C')
				mlx_image_to_window(map->mlx, image->coin, map->x * 50, map->y * 50);
			// else if (map_arr[map->y][map->x] == '0')
			// 	mlx_image_to_window(map->mlx, image->floor, map->x, map->y);
			else if (map_arr[map->y][map->x] == '1')
				mlx_image_to_window(map->mlx, image->chest, map->x * 50, map->y * 50);
			map->x++;
		}
		map->y++;
	}
	return ;
}

// void	image_window_border(t_image *image, t_map *map)
// {
// 	if ((map->y == 0) || (map->y == image->mpck->y_max))
// 	{
// 		while (map->x <= (image->mpck->x_max - 1))
// 		{
// 			mlx_image_to_window(map->mlx, image->coin, map->x * 10, map->y * 10);
// 			map->x++;
// 		}
// 		return ;
// 	}
// 	if ((map->x == 0) || (map->x == image->mpck->x_max))
// 	{
// 		while (map->y <= image->mpck->y_max)
// 		{
// 			mlx_image_to_window(map->mlx, image->coin, map->x * 10, map->y *10);
// 			map->y++;
// 		}
// 		return ;
// 	}
// 	return ;
// }
