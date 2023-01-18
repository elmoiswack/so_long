/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:44:08 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/18 19:52:01 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	images(t_map *map, t_mapcheck *mpck)
{
	t_image		*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
		ft_exit("malloc\nmalloc has failed in main!");
	image->chest = mlx_new_image(map->mlx, 128, 128);
	image->coin = mlx_new_image(map->mlx, 128, 128);
	image->floor = mlx_new_image(map->mlx, 128, 128);
	image->exit = mlx_new_image(map->mlx, 128, 128);
	image->walls = mlx_new_image(map->mlx, 128, 128);
	image->player = mlx_new_image(map->mlx, 128, 128);
	open_images(image);
	texture_image(image, map);
	image_window(image, map->map, map, mpck);
	return ;
}
