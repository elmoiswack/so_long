/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/27 16:56:38 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	find_start_point(phck, map_arr);
	while (1)
	{
		if ((mpck->c_count == 0) && (mpck->e_count == 0))
			return (1);
		map_check_path_xplus(phck, mpck, map_arr);
		map_check_path_ymin(phck, mpck, map_arr);
		map_check_path_xmin(phck, mpck, map_arr);
		map_check_path_yplus(phck, mpck, map_arr);
		map_check_path_checkpointcheck(phck);
	}
}

//if there are multiple directions
void	map_check_path_setcheckpoint(t_pathcheck *phck)
{
	phck->checkpoint_x = phck->p_x;
	phck->checkpoint_y = phck->p_y;
	return ;
}
//if one of the multiple directions is a dead end
void	map_check_path_checkpointcheck(t_pathcheck *phck)
{
	if (phck->checkpoint_x != phck->p_x)
	{
		phck->p_x = phck->checkpoint_x;
		return ;
	}
	if (phck->checkpoint_y != phck->p_y)
	{
		phck->p_y = phck->checkpoint_y;
		return ;
	}
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
				return (1);
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
	}
	return (0);
}