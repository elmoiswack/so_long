/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:47 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 16:46:14 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	free_structmap(t_map *map)
{
	if (map->player != NULL)
		mlx_delete_image(map->mlx, map->player);
	if (map->chest != NULL)
		mlx_delete_image(map->mlx, map->chest);
	if (map->exit != NULL)
		mlx_delete_image(map->mlx, map->exit);
	if (map->floor != NULL)
		mlx_delete_image(map->mlx, map->floor);
	if (map->coin != NULL)
		mlx_delete_image(map->mlx, map->coin);
	if (map->walls != NULL)
		mlx_delete_image(map->mlx, map->walls);
	if (map->map != NULL)
		ft_free_2d_array(map->map);
	free(map);
	return ;
}

void	ft_free_2d_array(char **array)
{
	int	y;

	y = 0;
	while (array[y] != NULL)
	{
		free(array[y]);
		y++;
	}
	free(array);
	return ;
}

void	texture_free(t_image *image)
{
	if (image->t_chest != NULL)
		free(image->t_chest);
	if (image->t_coin != NULL)
		free(image->t_coin);
	if (image->t_exit != NULL)
		free(image->t_exit);
	if (image->t_floor != NULL)
		free(image->t_floor);
	if (image->t_player != NULL)
		free(image->t_player);
	if (image->t_walls != NULL)
		free(image->t_walls);
	if (image != NULL)
		free(image);
	return ;
}

void	free_checkers_failed(t_map *map, t_mapcheck *mpck, char *str)
{
	free(mpck);
	ft_exit(str, map);
}
