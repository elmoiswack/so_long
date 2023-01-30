/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:03:33 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 05:13:57 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ending(t_map *map)
{
	mlx_delete_image(map->mlx, map->player);
	mlx_delete_image(map->mlx, map->chest);
	mlx_delete_image(map->mlx, map->exit);
	mlx_delete_image(map->mlx, map->floor);
	mlx_delete_image(map->mlx, map->coin);
	mlx_delete_image(map->mlx, map->walls);
	ft_free_2d_array(map->map, map->y_max);
	free(map->map_t_player);
	mlx_terminate(map->mlx);
	exit(EXIT_SUCCESS);
}