/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:28 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/18 15:58:12 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	window_creation(t_map *map, t_mapcheck	*mpck)
{	
	map->mlx = mlx_init(650, 450, "so_long", true);
	if (!map->mlx)
		ft_exit("mlx\nmlx init failed in window_creation!");
	images(map, mpck);
	mlx_loop(map->mlx);
	delete_images(map, map->image);
	mlx_terminate(map->mlx);
	return ;
}
