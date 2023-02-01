/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:14 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 15:11:01 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
	{
		free(str);
		free_checkers_failed(map, mpck,
			"map_line\nEither GNL or strjoin failed!");
	}
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

char	*map_line_helper(int fd, char *str, char *str_gnl)
{	
	char	*temp;

	while (str_gnl)
	{
		temp = ft_strjoin(str, str_gnl);
		free(str);
		str = temp;
		free(str_gnl);
		if (!str)
			return (NULL);
		str_gnl = get_next_line(fd);
		if (str_gnl && str_gnl[0] == '\n')
		{
			free(str);
			free(str_gnl);
			return (NULL);
		}
	}
	return (str);
}

char	*map_line(int fd, char *str)
{
	char	*str_gnl;

	str_gnl = get_next_line(fd);
	if (!str_gnl)
		return (NULL);
	str = map_line_helper(fd, str, str_gnl);
	if (!str)
		return (NULL);
	if (str[0] == '\n' || str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}
