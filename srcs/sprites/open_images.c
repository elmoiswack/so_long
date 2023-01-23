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

void	open_images_player(t_image *image)
{
	image->t_player = mlx_load_png("./images/player.png");
	if (!image->t_player)
		ft_exit("loading player!\n");
	return ;
}

void	open_images_coin(t_image *image)
{
	image->t_coin = mlx_load_png("./images/coin.png");
	if (!image->t_coin)
		ft_exit("loading coin!\n");
	return ;
}

void	open_images_floor_exit(t_image *image)
{
	image->t_floor = mlx_load_png("./images/floor.png");
	if (!image->t_floor)
		ft_exit("loading floors!");
	image->t_exit = mlx_load_png("./images/exit.png");
	if (!image->t_exit)
		ft_exit("loading exit!");
	return ;
}

void	open_images_walls(t_image *image)
{
	image->t_walls = mlx_load_png("./images/walls.png");
	if (!image->t_walls)
		ft_exit("loading walls!\n");
	image->t_chest = mlx_load_png("./images/chest.png");
	if (!image->t_chest)
		ft_exit("loading chest!\n");
	return ;
}

void	open_images(t_image *image)
{
	open_images_player(image);
	open_images_coin(image);
	open_images_floor_exit(image);
	open_images_walls(image);
	return ;
}
