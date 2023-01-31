/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:06 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 00:45:33 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	texture_image(t_image *image, t_map *map)
{
	map->coin = mlx_texture_to_image(map->mlx, image->t_coin);
	if (!map->coin)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for coin!", map);
	}
	map->player = mlx_texture_to_image(map->mlx, image->t_player);
	if (!map->player)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for player!", map);
	}
	map->exit = mlx_texture_to_image(map->mlx, image->t_exit);
	if (!map->exit)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for exit!", map);
	}
	map->floor = mlx_texture_to_image(map->mlx, image->t_floor);
	if (!map->floor)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for	floor!", map);
	}
	map->walls = mlx_texture_to_image(map->mlx, image->t_walls);
	if (!map->walls)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for walls!", map);
	}	
	map->chest = mlx_texture_to_image(map->mlx, image->t_chest);
	if (!map->chest)
	{
		texture_free(image);
		ft_exit("texture_image\ntexture to image failed for chest!", map);
	}	
	texture_free(image);
	return ;
}
