/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:59:40 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/23 18:33:29 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	button_key_hook(void *param)
{
	t_map *map;
	
	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D) && map->map[map->map_player_y][map->map_player_x + 1] != '1')
	{
		map->player->instances[0].x += 31;
		map->map_player_x += 1;
	}
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A) && map->map[map->map_player_y][map->map_player_x - 1] != '1')
	{
		map->player->instances[0].x -= 31;
		map->map_player_x -= 1;
	}
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) && map->map[map->map_player_y + 1][map->map_player_x] != '1')
	{
		map->player->instances[0].y += 31;
		map->map_player_y += 1;
	}	
	else if (mlx_is_key_down(map->mlx, MLX_KEY_W) && map->map[map->map_player_y - 1][map->map_player_x] != '1')
	{
		map->player->instances[0].y -= 31;
		map->map_player_y -= 1;
	}
}