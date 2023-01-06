/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/06 12:04:54 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(char **map_arr, int x, int y)
{
	t_pathcheck	*phck;
	
	phck = ft_calloc(1, sizeof(t_pathcheck));
	if (!phck)
		ft_exit("malloc\nmalloc has failed!");
	if (phck->p_x == 0 && phck->p_y == 0)
		map_check_p(map_arr, phck);
	phck->current_x = x;
	phck->current_y = y;
	phck->checkpoint_x = x;
	phck->checkpoint_y = y;
	while(1)
	{
		if (map_check_path_xplus(map_arr, phck) == -1)
		{
			phck->current_x = phck->checkpoint_x;
			phck->current_y = phck->checkpoint_y;
			map_check_path_xmin(map_arr, phck);
		}
		if (phck->current_x == phck->p_x && phck->current_y == phck->p_y)
			return (1);
	}
	return (-1);
}


int		map_check_p(char **map_arr, t_pathcheck	*phck)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		while (map_arr[phck->p_y][phck->p_x] != '\n')
		{
			if (map_arr[phck->p_y][phck->p_x] == 'P')
				return (1);
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
	}
	return (-1);
}