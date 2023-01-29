/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:59:40 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/29 17:31:43 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checker_collectibles_map(t_map *map)
{
	if (map->map[map->map_player_y][map->map_player_x] == 'C')
	{
		map->c_count--;
		map->map[map->map_player_y][map->map_player_x] = '0';
		//while (map->coin->instances[i] != map->coin->instances)
	}
	if (map->map[map->map_player_y][map->map_player_x] == 'E' && map->c_count == 0)
	{
		ft_printf("CONGRATS YOU HAVE COMPLETED THE MAP!!\n");
		mlx_terminate(map->mlx);
		exit(EXIT_SUCCESS);
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
	{
		map->player->instances[0].x += 32;
		map->map_player_x += 1;
		map->moves += 1;
		ft_printf("Amount of moves are: %i\n", map->moves);
		checker_collectibles_map(map);
	}
	else if (mlx_is_key_down(map->mlx, MLX_KEY_A) && map->map[map->map_player_y][map->map_player_x - 1] != '1')
	{
		map->player->instances[0].x -= 32;
		map->map_player_x -= 1;
		map->moves += 1;
		ft_printf("Amount of moves are: %i\n", map->moves);
		checker_collectibles_map(map);
	}
	else if (mlx_is_key_down(map->mlx, MLX_KEY_S) && map->map[map->map_player_y + 1][map->map_player_x] != '1')
	{
		map->player->instances[0].y += 32;
		map->map_player_y += 1;
		map->moves += 1;
		ft_printf("Amount of moves are: %i\n", map->moves);
		checker_collectibles_map(map);
	}	
	else if (mlx_is_key_down(map->mlx, MLX_KEY_W) && map->map[map->map_player_y - 1][map->map_player_x] != '1')
	{
		map->player->instances[0].y -= 32;
		map->map_player_y -= 1;
		map->moves += 1;
		ft_printf("Amount of moves are: %i\n", map->moves);
		checker_collectibles_map(map);
	}
}