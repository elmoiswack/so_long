/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:14 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 11:06:10 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	copy_variables(t_map *map, t_mapcheck *mpck)
{
	map->map_player_x = mpck->player_x;
	map->map_player_y = mpck->player_y;
	map->c_count = mpck->c_count;
	map->y_max = mpck->y_max;
	map->x_max = mpck->x_max;
	return ;
}

void	map_check_map(t_map *map, t_mapcheck *mpck)
{
	if (map_check_begin(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_check_middle(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_check_end(mpck, map->map) == -1)
		free_checkers_failed(map, mpck, "\0");
	if (map_checker_finalcheck(mpck) == -1)
		free_checkers_failed(map, mpck, "\0");
	return ;
}

char	**map_check_final(t_map *map, t_mapcheck *mpck)
{
	map_check_map(map, mpck);
	copy_variables(map, mpck);
	return (map->map);
}

char	**map_check_file(t_map *map, t_mapcheck *mpck, char **argv)
{
	int			fd;
	char		*map_str;
	char		*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_checkers_failed(map, mpck, "map\nNon existing map given!");
	str = ft_calloc(1, sizeof(char));
	if (!str)
		free_checkers_failed(map, mpck,
			"malloc\nallocation of str has failed in map_line!");
	map_str = map_line(fd, str);
	if (!map_str)
		free_checkers_failed(map, mpck,
			"map_line\nEither GNL or strjoin failed!");
	close (fd);
	map->map = ft_split(map_str, '\n');
	if (!map->map)
	{
		free(map_str);
		free_checkers_failed(map, mpck,
			"malloc\nallocation of map->map has failed in map_check_file!");
	}
	free(map_str);
	return (map_check_final(map, mpck));
}

char	*map_line(int fd, char *str)
{
	char	*str_gnl;

	str_gnl = get_next_line(fd);
	if (!str_gnl)
		return (NULL);
	while (str_gnl)
	{
		str = ft_strjoin(str, str_gnl);
		if (!str)
		{
			free(str);
			free(str_gnl);
			return (NULL);
		}
		str_gnl = get_next_line(fd);
		if (str_gnl && str_gnl[0] == '\n')
			return (NULL);
	}
	if (str[0] == '\n' || str[0] == '\0')
		return (NULL);
	free(str_gnl);
	return (str);
}
