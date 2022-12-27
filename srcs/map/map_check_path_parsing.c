/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:36 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/27 16:35:38 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_check_path_xplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y][phck->p_x + 1]) == '1' || (map_arr[phck->p_y][phck->p_x + 1] == '4'))
			return ;
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->p_x++;
		map_check_path_points(phck, mpck, map_arr);
		if((map_arr[phck->p_y + 1][phck->p_x] != '1') || (map_arr[phck->p_y - 1][phck->p_x] != '1'))
			map_check_path_setcheckpoint(phck);
	}
	return ;
}

void	map_check_path_xmin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y][phck->p_x - 1]) == '1' || (map_arr[phck->p_y][phck->p_x - 1] == '4'))
			return ;
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->p_x--;
		map_check_path_points(phck, mpck, map_arr);
		if((map_arr[phck->p_y + 1][phck->p_x] != '1') || (map_arr[phck->p_y - 1][phck->p_x] != '1'))
			map_check_path_setcheckpoint(phck);
	}
	return ;
}

void	map_check_path_yplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if (map_arr[phck->p_y + 1][phck->p_x] == '1' || (map_arr[phck->p_y + 1][phck->p_x] == '4'))
			return ;
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->p_y++;
		map_check_path_points(phck, mpck, map_arr);
		if((map_arr[phck->p_y][phck->p_x + 1] != '1') || (map_arr[phck->p_y][phck->p_x - 1] != '1'))
			map_check_path_setcheckpoint(phck);
	}
	return ;
}

void	map_check_path_ymin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if (map_arr[phck->p_y - 1][phck->p_x] == '1' || (map_arr[phck->p_y - 1][phck->p_x] == '4'))
			return ;
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->p_y--;
		map_check_path_points(phck, mpck, map_arr);
		if((map_arr[phck->p_y][phck->p_x + 1] != '1') || (map_arr[phck->p_y][phck->p_x - 1] != '1'))
			map_check_path_setcheckpoint(phck);
	}
	return ;
}