/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:59:43 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/13 15:52:50 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	open_images_player(t_image *image)
{
	image->player = mlx_load_png("./images/player.png");
	if (!image->player)
		ft_exit("loading player!\n");
	return ;
}

void	open_images_coin(t_image *image)
{
		image->coin = mlx_load_png("./images/coin.png");
	if (!image->coin)
		ft_exit("loading coin!\n");
	return ;
}

void	open_images_floor_exit(t_image *image)
{
	image->floor = mlx_load_png("./images/floor.png");
	if (!image->floor)
		ft_exit("loading floors!");
	image->exit = mlx_load_png("./images/exit.png");
	if (!image->exit)
		ft_exit("loading exit!");
	return ;
}

void	open_images_walls(t_image *image)
{
	image->walls = mlx_load_png("./images/walls.png");
	if (!image->walls)
		ft_exit("loading walls!\n");
	image->chest = mlx_load_png("./images/chest.png");
	if (!image->chest)
		ft_exit("loading chest!\n");
	return ;
}

void	open_images(t_image *image)
{
	open_images_player(image);
	open_images_coin(image);
	open_images_floor(image);
	open_images_walls(image);
	return ;	
}