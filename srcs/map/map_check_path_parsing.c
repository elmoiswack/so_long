/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:35:36 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/30 15:15:05 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_check_path_xplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	printf("direc = %i\n", phck->directions);
	printf("mapy = %c\n", map_arr[phck->p_y - 1][phck->p_x]);
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y][phck->p_x + 1] == '1') || (map_arr[phck->p_y][phck->p_x + 1] == '4'))
		{
			phck->directions -= 1;
			return ;
		}	
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->directions = 4;
		if (((map_arr[phck->p_y - 1][phck->p_x] != '1') && (map_arr[phck->p_y - 1][phck->p_x] != '4'))
			|| ((map_arr[phck->p_y + 1][phck->p_x] != '1') && (map_arr[phck->p_y + 1][phck->p_x] != '4')))
			if (map_check_path_setcheckpoint(phck, map_arr) == 1)
				return ;
		phck->p_x++;
		map_check_path_points(phck, mpck, map_arr);
	}
	printf("direc = %i\n", phck->directions);
	return ;
}

void	map_check_path_xmin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y][phck->p_x - 1] == '1') || (map_arr[phck->p_y][phck->p_x - 1] == '4'))
		{
			phck->directions -= 1;
			return ;
		}
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->directions = 4;
		if (((map_arr[phck->p_y + 1][phck->p_x] != '1') && (map_arr[phck->p_y + 1][phck->p_x] != '4'))
			|| ((map_arr[phck->p_y - 1][phck->p_x] != '1') && (map_arr[phck->p_y - 1][phck->p_x] != '4')))
			map_check_path_setcheckpoint(phck, map_arr);
		phck->p_x--;
		map_check_path_points(phck, mpck, map_arr);
	}
	return ;
}

void	map_check_path_yplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y + 1][phck->p_x] == '1') || (map_arr[phck->p_y + 1][phck->p_x] == '4'))
		{
			phck->directions -= 1;
			return ;
		}
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->directions = 4;
		if (((map_arr[phck->p_y][phck->p_x + 1] != '1') && (map_arr[phck->p_y][phck->p_x + 1] != '4'))
			|| ((map_arr[phck->p_y][phck->p_x - 1] != '1') && (map_arr[phck->p_y][phck->p_x - 1] != '4')))
			map_check_path_setcheckpoint(phck, map_arr);
		phck->p_y++;
		map_check_path_points(phck, mpck, map_arr);
	}
	return ;
}

void	map_check_path_ymin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr)
{
	while (map_arr[phck->p_y][phck->p_x])
	{
		if ((map_arr[phck->p_y - 1][phck->p_x] == '1') || (map_arr[phck->p_y - 1][phck->p_x] == '4'))
		{
			phck->directions -= 1;
			return ;
		}
		map_arr[phck->p_y][phck->p_x] = '4';
		phck->directions = 4;
		if (((map_arr[phck->p_y][phck->p_x + 1] != '1') && (map_arr[phck->p_y][phck->p_x + 1] != '4'))
			|| ((map_arr[phck->p_y][phck->p_x - 1] != '1') && (map_arr[phck->p_y][phck->p_x - 1] != '4')))
			map_check_path_setcheckpoint(phck, map_arr);
		phck->p_y--;
		map_check_path_points(phck, mpck, map_arr);
	}
	return ;
}