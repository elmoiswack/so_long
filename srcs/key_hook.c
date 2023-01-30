/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:59:40 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 05:06:04 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_recreation(t_map *map)
{
	mlx_delete_image(map->mlx, map->player);
	map->map_t_player = mlx_load_png("./images/player.png");
	if (!map->map_t_player)
		ft_exit("player_recreation\nallocation of player texture failed");
	map->player = mlx_texture_to_image(map->mlx, map->map_t_player);
	if (!map->player)
		ft_exit("player_recreation\nallocation of player failed");
	mlx_image_to_window(map->mlx, map->player, map->map_player_x * 32, map->map_player_y * 32);
	return ;
}

void	checker_points_map(t_map *map)
{
	if (map->map[map->map_player_y][map->map_player_x] == 'C')
	{
		map->c_count--;
		map->map[map->map_player_y][map->map_player_x] = '0';
		mlx_image_to_window(map->mlx, map->floor, map->map_player_x * 32, map->map_player_y * 32);
		player_recreation(map);
		return ;
	}
	if (map->map[map->map_player_y][map->map_player_x] == 'E' && map->c_count != 0)
	{
		ft_printf("I NEED ALL THE COINS!!!!!!!\n");
		return ;
	}
	if (map->map[map->map_player_y][map->map_player_x] == 'E' && map->c_count == 0)
	{
		ending(map);
	}
	return ;
}

void	button_key_hook(void *param)
{
	t_map *map;
	
	map = (t_map *) param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D) && mlx_is_key_down(map->mlx, MLX_KEY_A))
		return ;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_W) && mlx_is_key_down(map->mlx, MLX_KEY_S))
		return ;
	else if (mlx_is_key_down(map->mlx, MLX_KEY_D) && map->map[map->map_player_y][map->map_player_x + 1] != '1')
		move_right(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A) && map->map[map->map_player_y][map->map_player_x - 1] != '1')
		move_left(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) && map->map[map->map_player_y + 1][map->map_player_x] != '1')
		move_down(map);
	else if (mlx_is_key_down(map->mlx, MLX_KEY_W) && map->map[map->map_player_y - 1][map->map_player_x] != '1')
		move_up(map);
}