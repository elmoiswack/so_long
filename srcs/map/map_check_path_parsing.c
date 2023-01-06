#include "../../so_long.h"

int	map_check_path_xplus(char **map_arr, t_pathcheck *phck)
{	
	while (map_arr[phck->current_y][phck->current_x] != '1')
	{
		if (map_arr[phck->current_y][phck->current_x + 1] == '1')
			break ;
		phck->current_x++;
		if (map_arr[phck->current_y][phck->current_x] == 'P')
			return (1);
	}
	if (map_arr[phck->current_y + 1][phck->current_x] != '1')
		return (map_check_path_yplus(map_arr, phck));
	if (map_arr[phck->current_y - 1][phck->current_x] != '1')
		return (map_check_path_ymin(map_arr, phck));
	return (-1);
}

int	map_check_path_xmin(char **map_arr, t_pathcheck *phck)
{
	while (map_arr[phck->current_y][phck->current_x] != '1')
	{
		if (map_arr[phck->current_y][phck->current_x - 1] == '1')
			break ;
		phck->current_x--;
		if (map_arr[phck->current_y][phck->current_x] == 'P')
			return (1);
	}
	if (map_arr[phck->current_y + 1][phck->current_x] != '1')
		return (map_check_path_yplus(map_arr, phck));
	if (map_arr[phck->current_y - 1][phck->current_x] != '1')
		return (map_check_path_ymin(map_arr, phck));
	return (-1);
}

int	map_check_path_yplus(char **map_arr, t_pathcheck *phck)
{
	while (map_arr[phck->current_y][phck->current_x] != '1')
	{
		if (map_arr[phck->current_y + 1][phck->current_x] == '1')
			break ;
		phck->current_y++;
		if (map_arr[phck->current_y][phck->current_x] == 'P')
			return (1);
	}
	if (map_arr[phck->current_y][phck->current_x + 1] != '1')
		return (map_check_path_xplus(map_arr, phck));
	if (map_arr[phck->current_y][phck->current_x - 1] != '1')
		return (map_check_path_xmin(map_arr, phck));
	return (-1);
}

int	map_check_path_ymin(char **map_arr, t_pathcheck *phck)
{
	while (map_arr[phck->current_y][phck->current_x] != '1')
	{
		if (map_arr[phck->current_y - 1][phck->current_x] == '1')
			break ;
		phck->current_y--;
		if (map_arr[phck->current_y][phck->current_x] == 'P')
			return (1);
	}
	if (map_arr[phck->current_y][phck->current_x + 1] != '1')
		return (map_check_path_xplus(map_arr, phck));
	if (map_arr[phck->current_y][phck->current_x - 1] != '1')
		return (map_check_path_xmin(map_arr, phck));
	return (-1);
}