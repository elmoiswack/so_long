/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:26:37 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/17 17:29:22 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	delete_images(t_map *map, t_image *image)
{
	mlx_delete_image(map->mlx, image->chest);
	mlx_delete_image(map->mlx, image->floor);
	mlx_delete_image(map->mlx, image->walls);
	mlx_delete_image(map->mlx, image->exit);
	mlx_delete_image(map->mlx, image->player);
	mlx_delete_image(map->mlx, image->coin);
	return ;
}