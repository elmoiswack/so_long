/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:28 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/19 11:38:22 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_creation(t_map *map, t_mapcheck	*mpck)
{
	map->window_x = 1280;
	map->window_y = 920;
	map->window_center_x = map->window_x / 2;
	map->window_center_y = map->window_y / 2;
	map->mlx = mlx_init(map->window_x, map->window_y, "so_long", true);
	if (!map->mlx)
		ft_exit("mlx\nmlx init failed in window_creation!");
	images(map, mpck);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return ;
}
