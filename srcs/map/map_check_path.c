/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/27 13:21:43 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	find_start_point(phck, map_arr);
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((mpck->c_count == 0) && (mpck->e_count == 0) && (mpck->p_count == 0))
			return (1);
		
	}
}
//if there are multiple directions
void	map_check_path_setcheckpoint(t_pathcheck *phck)
{
	phck->checkpoint_x = phck->p_x;
	phck->checkpoint_y = phck->p_y;
}
//if one of the multiple directions is a dead end
void	map_check_path_checkpointcheck(t_pathcheck *phck)
{
	if (phck->checkpoint_x != phck->p_x)
	{
		phck->p_x = phck->checkpoint_x;
		return (map_check_path_checker_y);
	}
	if (phck->checkpoint_y != phck->p_y)
	{
		phck->p_y = phck->checkpoint_y;
		return (map_check_path_checker_x);
	}
}

int	map_check_path_checker_y(t_pathcheck *phck, char **map_arr)
{
	if (map_arr[phck->p_y + 1][phck->p_x] != '1')
		return (phck->p_y++);
	if (map_arr[phck->p_y - 1][phck->p_x] != '1')
		return (phck->p_y--);
	return (0);
}

int	map_check_path_checker_x(t_pathcheck *phck, char **map_arr)
{
	if (map_arr[phck->p_y][phck->p_x + 1] != '1')
		return (phck->p_x++);
	if (map_arr[phck->p_y][phck->p_x - 1] != '1')
		return (phck->p_x--);
	return (0);
}

int	map_check_path_points(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	if (map_arr[phck->p_y][phck->p_x] == 'E')
		return (mpck->e_count - 1);
	if (map_arr[phck->p_y][phck->p_x] == 'P')
		return (mpck->p_count - 1);
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
				return (1);
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
	}
	return (0);
}