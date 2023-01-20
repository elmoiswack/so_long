/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:59:40 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/20 23:43:43 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	button_key_hook(void *param)
{
	t_map *map;
	
	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (mlx_is_key_down(map->mlx, MLX_KEY_D) && map->map[map->y][map->x + 1] != '1')
		map->mlx_image->instances[0].x += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_A) && map->map[map->y][map->x - 1] != '1')
		map->mlx_image->instances[0].x -= 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_S) && map->map[map->y + 1][map->x] != '1')
		map->mlx_image->instances[0].y += 5;
	if (mlx_is_key_down(map->mlx, MLX_KEY_W) && map->map[map->y - 1][map->x] != '1')
		map->mlx_image->instances[0].y -= 5;
}