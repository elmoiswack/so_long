/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:06:28 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 16:29:02 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_window_size(t_map *map)
{
	int	times;
	int	y_check;
	int	count;

	times = 36;
	y_check = 8;
	count = 0;
	while (1)
	{
		while (count != 3)
		{
			if (map->y_max == y_check)
				return (times);
			y_check++;
			count++;
		}
		count = 0;
		times--;
	}
	return (0);
}

void	window_creation(t_map *map)
{
	int	times;

	map->window_x = map->x_max * 32;
	if (map->y_max < 8)
		map->window_y = map->y_max * 37;
	if (map->y_max >= 8)
	{
		times = get_window_size(map);
		map->window_y = map->y_max * times;
	}	
	map->mlx = mlx_init(map->window_x, map->window_y, "so_long", 0);
	if (!map->mlx)
		ft_exit("window_creation\nmlx_init failed in window_creation!", map);
	images(map);
	mlx_loop_hook(map->mlx, &button_key_hook, map);
	mlx_loop(map->mlx);
	free_structmap(map);
	mlx_terminate(map->mlx);
	return ;
}
