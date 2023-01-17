/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:06 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/17 16:44:22 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	texture_image(t_image *image, t_map *map)
{
	image->coin = mlx_texture_to_image(map->mlx, image->coin);
	image->player = mlx_texture_to_image(map->mlx, image->player);
	image->exit = mlx_texture_to_image(map->mlx, image->exit);
	image->floor = mlx_texture_to_image(map->mlx, image->floor);
	image->walls = mlx_texture_to_image(map->mlx, image->walls);
	image->chest = mlx_texture_to_image(map->mlx, image->chest);
	return ;
}