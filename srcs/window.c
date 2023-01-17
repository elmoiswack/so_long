/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:28 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/17 17:41:38 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_creation(t_map *map)
{	
	map->mlx = mlx_init(1920, 1080, "so_long", true);
	if (!map->mlx)
		ft_exit("mlx\nmlx init failes in window_creation!");
	images(map);
	mlx_loop(map->mlx);
	delete_images(map, map->image);
	mlx_terminate(map->mlx);
	return ;
}