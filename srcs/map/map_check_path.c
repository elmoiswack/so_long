/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:49:48 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 16:29:48 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	path_checker(t_pathcheck *phck, t_mapcheck *mpck, char **map_copy)
{
	int			start_x;
	int			start_y;

	start_x = phck->p_x;
	start_y = phck->p_y;
	mpck->player_x = phck->p_x;
	mpck->player_y = phck->p_y;
	if (map_check_valid_path(phck, map_copy, start_x, start_y) == 1)
	{
		free_mapcopy(map_copy, mpck->y_max);
		free(phck);
		return (1);
	}
	free_mapcopy(map_copy, mpck->y_max);
	free(phck);
	return (-1);
}

int	map_check_path(t_mapcheck *mpck, char **map_arr, int x, int y)
{
	t_pathcheck	*phck;
	char		**map_copy;

	phck = ft_calloc(1, sizeof(t_pathcheck));
	if (!phck)
		return (-1);
	if (map_check_p(mpck, map_arr, phck) == -1)
	{
		free(mpck);
		ft_free_2d_array(map_arr);
		return (-1);
	}		
	map_copy = map_copy_function(map_arr, mpck);
	if (!map_copy)
	{
		free(phck);
		ft_free_2d_array(map_arr);
		return (-1);
	}
	phck->destination_x = x;
	phck->destination_y = y;
	if (path_checker(phck, mpck, map_copy) == 1)
		return (1);
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
	return (-1);
}

void	free_mapcopy(char **map_copy, int y)
{
	if (y > 1)
	{
		while (y >= 0)
		{
			free(map_copy[y]);
			y--;
		}
	}
	free(map_copy);
	return ;
}

char	**map_copy_function(char **map_arr, t_mapcheck *mpck)
{
	int		x;
	int		y;
	char	**map_copy;

	y = 0;
	map_copy = malloc((mpck->y_max + 2) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (y <= mpck->y_max)
	{
		map_copy[y] = malloc(ft_strlen(map_arr[y]) + 1);
		if (!map_copy[y])
		{
			free_mapcopy(map_copy, y);
			return (NULL);
		}
		x = 0;
		while (map_arr[y][x])
		{
			map_copy[y][x] = map_arr[y][x];
			x++;
		}
		map_copy[y][x] = '\0';
		y += 1;
	}
	map_copy[y] = NULL;
	return (map_copy);
}
