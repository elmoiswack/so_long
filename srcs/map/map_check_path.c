/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/23 16:21:37 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	find_p_e(phck, map_arr);
	while (map_arr[phck->p_x][phck->p_y])
	{
		if ((phck->p_x > 1) && (phck->p_y > 1) && (phck->p_x < mpck->x_max)
			&& (phck->p_y < mpck->y_max) && (map_arr[phck->p_x][phck->p_y] == '0'))
			return (1);
			
	}
}

int	find_p_e(t_pathcheck *phck, char **map_arr)
{
	while (map_arr[phck->p_x][phck->p_y])
	{
		while (map_arr[phck->p_x][phck->p_y])
		{
			if (map_arr[phck->p_x][phck->p_y] == 'P')
				break ;
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
	}
	while (map_arr[phck->e_x][phck->e_y])
	{
		while (map_arr[phck->e_x][phck->e_y])
		{
			if (map_arr[phck->e_x][phck->e_y] == 'E')
				return (1);
			phck->e_x++;
		}
		phck->e_x = 0;
		phck->e_y++;
	}
	return (0);
}