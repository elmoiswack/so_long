/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:06 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/27 17:08:00 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	texture_free(t_image *image)
{
	free(image->t_chest);
	free(image->t_coin);
	free(image->t_exit);
	free(image->t_floor);
	free(image->t_player);
	free(image->t_walls);
	free(image);
	return ;
}

void	texture_image(t_image *image, t_map *map)
{
	map->coin = mlx_texture_to_image(map->mlx, image->t_coin);
	if (!map->coin)
		ft_exit("texture coin!");
	map->player = mlx_texture_to_image(map->mlx, image->t_player);
	if (!map->player)
		ft_exit("texture player!");
	map->exit = mlx_texture_to_image(map->mlx, image->t_exit);
	if (!map->exit)
		ft_exit("texture exit!");
	map->floor = mlx_texture_to_image(map->mlx, image->t_floor);
	if (!map->floor)
		ft_exit("texture floor!");
	map->walls = mlx_texture_to_image(map->mlx, image->t_walls);
	if (!map->walls)
		ft_exit("texture walls!");
	map->chest = mlx_texture_to_image(map->mlx, image->t_chest);
	if (!map->chest)
		ft_exit("texture chest!");
	texture_free(image);
	return ;
}
