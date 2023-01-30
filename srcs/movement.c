/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 01:55:40 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 05:01:24 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_map *map)
{
	map->player->instances[0].y -= 32;
	map->map_player_y -= 1;
	map->moves += 1;
	ft_printf("Amount of moves are: %i\n", map->moves);
	checker_points_map(map);
	return ;
}

void	move_down(t_map *map)
{
	map->player->instances[0].y += 32;
	map->map_player_y += 1;
	map->moves += 1;
	ft_printf("Amount of moves are: %i\n", map->moves);
	checker_points_map(map);
	return ;
}

void	move_left(t_map *map)
{
	map->player->instances[0].x -= 32;
	map->map_player_x -= 1;
	map->moves += 1;
	ft_printf("Amount of moves are: %i\n", map->moves);
	checker_points_map(map);
	return ;
}

void	move_right(t_map *map)
{
	map->player->instances[0].x += 32;
	map->map_player_x += 1;
	map->moves += 1;
	ft_printf("Amount of moves are: %i\n", map->moves);
	checker_points_map(map);
	return ;
}