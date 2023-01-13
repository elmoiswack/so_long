/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:36:09 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/13 16:00:48 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	image_window(t_image *image, char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_arr[y][x])
	{
		if ((x == 0) || (y == 0) || (x == image->mpck->x_max) || (y == image->mpck->y_max))
			mlx_image_to_window(image->mlx, image->walls, x, y);
		else if (map_arr[y][x] == 'P')
			mlx_image_to_window(image->mlx, image->player, x, y);
		else if (map_arr[y][x] == 'E')
			mlx_image_to_window(image->mlx, image->exit, x, y);
		else if (map_arr[y][x] == 'C')
			mlx_image_to_window(image->mlx, image->coin, x, y);
		else if (map_arr[y][x] == '0')
			mlx_image_to_window(image->mlx, image->floor, x, y);
		else if ((x >= 1 && x < image->mpck->x_max) && (y >= 1 && y < image->mpck->y_max) && (map_arr[y][x] == '1'))
			mlx_image_to_window(image->mlx, image->chest, x, y);
		x++;
		y++;
	}
	return ;
}