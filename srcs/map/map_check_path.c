/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/30 15:12:58 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	static int	max;
	
	max = mpck->x_max * mpck ->y_max;
	phck->directions = 4;
	find_start_point(phck, map_arr);
	while (max > 0)
	{
		if ((mpck->c_count == 0) && (mpck->e_count == 0))
			return (1);
		while (phck->directions != 0)
		{
			max -= 5;
			printf("%i\n", max);
			map_check_path_xplus(phck, mpck, map_arr);
			map_check_path_ymin(phck, mpck, map_arr);
			map_check_path_xmin(phck, mpck, map_arr);
			map_check_path_yplus(phck, mpck, map_arr);
		}
		max -= 5;
		printf("%i\n", max);
		map_check_path_resetxy(phck);
	}
	return (0);
}

int	map_check_path_setcheckpoint(t_pathcheck *phck, char **map_arr)
{
	if ((map_arr[phck->checkpoint_y + 1][phck->checkpoint_x] == '0') 
	|| (map_arr[phck->checkpoint_y - 1][phck->checkpoint_x] == '0')
	|| (map_arr[phck->checkpoint_y][phck->checkpoint_x + 1] == '0') 
	|| (map_arr[phck->checkpoint_y][phck->checkpoint_x - 1] == '0'))
	{
		phck->temp_x = phck->p_x;
		phck->temp_y = phck->p_y;
		phck->p_x = phck->checkpoint_x;	
		phck->p_y = phck->checkpoint_y;
		return (1);
	}
	else
	{
		phck->checkpoint_x = phck->p_x;
		phck->checkpoint_y = phck->p_y;
	}
	return (0);
}

void map_check_path_resetxy(t_pathcheck *phck)
{
	if (phck->temp_x != 0 && phck->temp_y != 0)
	{
		phck->p_x = phck->temp_x;
		phck->p_y = phck->temp_y;
	}
	else
	{
		phck->p_x = phck->checkpoint_x;
		phck->p_y = phck->checkpoint_y;
	}
	phck->directions = 4;
	return ;
}

int	map_check_path_points(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	if (map_arr[phck->p_y][phck->p_x] == 'E')
		return (mpck->e_count - 1);
	if (map_arr[phck->p_y][phck->p_x] == 'C')
		return (mpck->c_count - 1);
	return (0);
}

int	find_start_point(t_pathcheck *phck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		while (map_arr[phck->p_y][phck->p_x])
		{
			if (map_arr[phck->p_y][phck->p_x] == 'P')
			{
				phck->checkpoint_x = phck->p_x;
				phck->checkpoint_y = phck->p_y;
				return (1);
			}	
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
	}
	return (0);
}