/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:28 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 00:47:48 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_creation(t_map *map, t_mapcheck	*mpck)
{
	map->window_x = mpck->x_max * 32;
	map->window_y = mpck->y_max * 37;
	if (!(map->mlx = mlx_init(map->window_x, map->window_y, "so_long", 0)))
		ft_exit("making window\nmlx_init failed in window_creation!");
	if (!map->mlx)
		ft_exit("mlx\nmlx init failed in window_creation!");
	images(map);
	mlx_loop_hook(map->mlx, &button_key_hook, map);
	mlx_loop(map->mlx);
	return ;
}
