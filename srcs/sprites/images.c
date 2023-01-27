/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:44:08 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/27 16:28:40 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	images(t_map *map)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
		ft_exit("malloc\nmalloc has failed in main!");
	map->chest = mlx_new_image(map->mlx, 64, 64);
	map->coin = mlx_new_image(map->mlx, 64, 64);
	map->floor = mlx_new_image(map->mlx, 64, 64);
	map->exit = mlx_new_image(map->mlx, 64, 64);
	map->walls = mlx_new_image(map->mlx, 64, 64);
	map->player = mlx_new_image(map->mlx, 64, 64);
	open_images(image);
	texture_image(image, map);
	image_window(map->map, map);
	return ;
}
