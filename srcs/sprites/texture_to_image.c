/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:39:06 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/20 19:08:39 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	texture_image(t_image *image, t_map *map)
{
	image->coin = mlx_texture_to_image(map->mlx, image->coin);
	if (!image->coin)
		ft_exit("texture coin!");
	image->player = mlx_texture_to_image(map->mlx, image->player);
	if (!image->player)
		ft_exit("texture player!");
	image->exit = mlx_texture_to_image(map->mlx, image->exit);
	if (!image->exit)
		ft_exit("texture exit!");
	image->floor = mlx_texture_to_image(map->mlx, image->floor);
	if (!image->floor)
		ft_exit("texture floor!");
	image->walls = mlx_texture_to_image(map->mlx, image->walls);
	if (!image->walls)
		ft_exit("texture walls!");
	image->chest = mlx_texture_to_image(map->mlx, image->chest);
	if (!image->chest)
		ft_exit("texture chest!");
	return ;
}
