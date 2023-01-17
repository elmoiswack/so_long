/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:14 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/17 14:10:11 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**map_check_file(t_map *map, t_mapcheck *mpck, char **argv)
{
	int			fd;
	char		*map_str;
	char		*str;

	fd = open(argv[1], O_RDONLY);
	str = ft_calloc(1, sizeof(char));
	if (!str)
		ft_exit("malloc\nmalloc has failed in map_line!");
	map_str = map_line(fd, str);
	close (fd);
	map->map = ft_split(map_str, '\n');
	if (!map->map)
	{
		free(map->map);
		free(map);
		free(map_str);
		ft_exit("malloc\nmalloc has failed in map_check_file!");
	}
	free(map_str);
	map_check_begin(mpck, map->map);
	map_check_middle(mpck, map->map);
	map_check_end(mpck, map->map);
	map_checker_finalcheck(mpck);
	return (map->map);
}

char	*map_line(int fd, char *str)
{
	char	*str_gnl;

	str_gnl = get_next_line(fd);
	if (!str_gnl)
		ft_exit("get next line\nget next line has failed in map_line!");
	while (str_gnl)
	{
		str = ft_strjoin(str, str_gnl);
		if (!str)
		{
			free(str);
			free(str_gnl);
			ft_exit("strjoin\nstrjoin has failed in map_line!");
		}
		str_gnl = get_next_line(fd);
		if (str_gnl && str_gnl[0] == '\n')
			ft_exit("map\nmap is invalid in map_line!");
	}
	if (str[0] == '\n' || str[0] == '\0')
		ft_exit("map\nmap is invalid in map_line!");
	free(str_gnl);
	return (str);
}
