/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:17 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 15:41:44 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_begin(t_mapcheck *mpck, char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_arr[y][x])
	{
		if (map_arr[y][x] != '1')
			return (exit_printf("Error in map\nupper border is invalid!"));
		x++;
	}
	mpck->x_max = x;
	return (1);
}

int	map_check_middle(t_mapcheck *mpck, char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map_arr[mpck->y_max])
		mpck->y_max++;
	mpck->y_max = mpck->y_max - 1;
	while (y < mpck->y_max)
	{
		while (map_arr[y][x])
		{
			if (map_check_checker(mpck, map_arr, x, y) == -1)
				return (-1);
			x++;
		}
		if (x != mpck->x_max)
			return (exit_printf("Error in map\nthe map isnt the same size!"));
		y++;
		x = 0;
	}
	return (1);
}

int	map_check_end(t_mapcheck *mpck, char **map_arr)
{
	int	x;

	x = 0;
	while (map_arr[mpck->y_max][x])
	{
		if (map_arr[mpck->y_max][x] != '1')
			return (exit_printf("Error in map\nlower border is invalid!"));
		x++;
	}
	if (x != mpck->x_max)
		return (exit_printf("Error in map\nthe map isnt the same size!"));
	return (1);
}

int	map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y)
{
	if ((map_arr[y][0] != '1') || (map_arr[y][mpck->x_max - 1] != '1'))
		return (exit_printf("Error in map\nleft or right border is invaled!"));
	else if (map_arr[y][x] == 'P')
	{
		mpck->p_count += 1;
		return (1);
	}
	else if (map_arr[y][x] == 'E')
	{
		mpck->e_count += 1;
		if (map_check_path(mpck, map_arr, x, y) == -1)
			return (exit_printf("Error in map\nnot a valid path to 'E'!"));
		return (1);
	}
	else if (map_arr[y][x] == 'C')
	{
		mpck->c_count += 1;
		if (map_check_path(mpck, map_arr, x, y) == -1)
			exit_printf("Error in map\nnot a valid path to 'C'!");
		return (1);
	}
	else if (map_arr[y][x] == '0' || map_arr[y][x] == '1')
		return (1);
	return (exit_printf("Error in map\nstop adding random stuff!"));
}

int	map_checker_finalcheck(t_mapcheck *mpck)
{	
	if (mpck->e_count == 0)
		return (exit_printf("Error in map\nno exit found!"));
	if (mpck->e_count > 1)
		return (exit_printf("Error in map\ntoo many exit found!"));
	if (mpck->p_count == 0)
		return (exit_printf("Error in map\nno start found!"));
	if (mpck->p_count > 1)
		return (exit_printf("Error in map\ntoo many start found!"));
	if (mpck->c_count < 1)
		return (exit_printf("Error in map\nno collictibles found!"));
	return (1);
}
