/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/30 05:16:53 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_path(t_mapcheck *mpck, char **map_arr, int x, int y)
{
	t_pathcheck	*phck;
	char		**map_copy;
	int			start_x;
	int			start_y;

	phck = ft_calloc(1, sizeof(t_pathcheck));
	if (!phck)
		ft_exit("malloc\nmalloc has failed in map_check_path!");
	if (phck->p_x == 0 && phck->p_y == 0)
		map_check_p(mpck, map_arr, phck);
	map_copy = map_copy_function(map_arr, mpck);
	phck->destination_x = x;
	phck->destination_y = y;
	start_x = phck->p_x;
	start_y = phck->p_y;
	mpck->player_x = phck->p_x;
	mpck->player_y = phck->p_y;
	if (map_check_valid_path(phck, map_copy, start_x, start_y) == 1)
	{
		ft_free_2d_array(map_copy, mpck->y_max);
		free(phck);
		return (1);
	}
	ft_free_2d_array(map_copy, mpck->y_max);
	return (-1);
}

int	map_check_p(t_mapcheck *mpck, char **map_arr, t_pathcheck *phck)
{
	int	check;

	check = 0;
	while (check < mpck->y_max)
	{
		while (phck->p_x <= mpck->x_max)
		{
			if (map_arr[phck->p_y][phck->p_x] == 'P')
				return (1);
			phck->p_x++;
		}
		phck->p_x = 0;
		phck->p_y++;
		check++;
	}
	if (check == mpck->y_max)
		ft_exit("map\nno 'P' found!");
	return (-1);
}

char	**map_copy_function(char **map_arr, t_mapcheck *mpck)
{
	int		x;
	int		y;
	char	**map_copy;

	x = 0;
	y = 0;
	map_copy = malloc(mpck->y_max * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (y <= mpck->y_max)
	{
		map_copy[y] = malloc(ft_strlen(map_arr[y]) + 1);
		if (!map_copy[y])
		{
			ft_free_2d_array(map_copy, y);
			ft_exit("malloc\nallocation failed in map_copy_function!");
		}
		while (map_arr[y][x])
		{
			map_copy[y][x] = map_arr[y][x];
			x++;
		}
		map_copy[y][x] = '\0';
		x = 0;
		y += 1;
	}
	return (map_copy);
}
