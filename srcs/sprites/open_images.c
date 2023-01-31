/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:43 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/23 16:06:59 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	open_images_player(t_image *image)
{
	image->t_player = mlx_load_png("./images/player.png");
	if (!image->t_player)
		return (-1);
	return (1);
}

int	open_images_coin(t_image *image)
{
	image->t_coin = mlx_load_png("./images/coin.png");
	if (!image->t_coin)
		return (-1);
	return (1);
}

int	open_images_floor_exit(t_image *image)
{
	image->t_floor = mlx_load_png("./images/floor.png");
	if (!image->t_floor)
		return (-1);
	image->t_exit = mlx_load_png("./images/exit.png");
	if (!image->t_exit)
		return (-1);
	return (1);
}

int	open_images_walls(t_image *image)
{
	image->t_walls = mlx_load_png("./images/walls.png");
	if (!image->t_walls)
		return (-1);
	image->t_chest = mlx_load_png("./images/chest.png");
	if (!image->t_chest)
		return (-1);
	return (1);
}

int	open_images(t_image *image)
{
	if (open_images_player(image) == -1)
		return (-1);
	if (open_images_coin(image) == -1)
		return (-1);
	if (open_images_floor_exit(image) == -1)
		return (-1);
	if (open_images_walls(image) == -1)
		return (-1);
	return (1);
}
