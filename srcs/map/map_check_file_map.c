/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:17 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/12 11:58:58 by dhussain         ###   ########.fr       */
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
			ft_exit("map\nupper border is invalid!");
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
			map_check_checker(mpck, map_arr, x, y);
			x++;
		}
		if (x != mpck->x_max)
			ft_exit("map\nthe map isnt the same size!");
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
			ft_exit("map\nlower border is invalid!");
		x++;
	}
	if (x != mpck->x_max)
		ft_exit("map\nthe map isnt the same size!");
	return (1);
}

int	map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y)
{
	if ((map_arr[y][0] != '1') || (map_arr[y][mpck->x_max - 1] != '1'))
		ft_exit("map\nborder left or right is invalid!");
	else if (map_arr[y][x] == 'P')
	{
		mpck->p_count += 1;
		return (1);
	}
	else if (map_arr[y][x] == 'E')
	{
		mpck->e_count += 1;
		if (map_check_path(mpck, map_arr, x, y) == -1)
			ft_exit("map, not a valid path to 'E'!");
		return (1);
	}
	else if (map_arr[y][x] == 'C')
	{
		mpck->c_count += 1;
		if (map_check_path(mpck, map_arr, x, y) == -1)
			ft_exit("map, not a valid path to 'C'!");
		return (1);
	}
	else if (map_arr[y][x] == '0' || map_arr[y][x] == '1')
		return (1);
	ft_exit("map\nstop adding random stuff!");
	return (-1);
}

int	map_checker_finalcheck(t_mapcheck *mpck)
{	
	if (mpck->e_count == 0)
		ft_exit("map\nno exit found!");
	if (mpck->e_count > 1)
		ft_exit("map\ntoo many exit found!");
	if (mpck->p_count == 0)
		ft_exit("map\nno start found!");
	if (mpck->p_count > 1)
		ft_exit("map\ntoo many start found!");
	if (mpck->c_count < 1)
		ft_exit("map\nno collictibles found!");
	if (mpck->x_max == (mpck->y_max + 1))
		ft_exit("map\nmap isn't rectangular!");
	return (1);
}
