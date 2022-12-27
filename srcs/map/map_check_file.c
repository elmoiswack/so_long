/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:14 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/27 12:39:05 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check_file(char **argv)
{
	int			fd;
	int			check;
	t_map		*map;
	t_mapcheck	*mpck;
	char		*map_str;

	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit("malloc\nmalloc has failed!");
	mpck = ft_calloc(1, sizeof(t_mapcheck));
	if (!mpck)
		ft_exit("malloc\nmalloc has failed!");
	map_str = map_line(fd);
	close (fd);
	map->map = ft_split(map_str, '\n');
	if (!map->map)
	{
		free(map->map);
		free(map);
		free(map_str);
		free(mpck);
		ft_exit("malloc\nmalloc has failed!");
	}
	free(map_str);
	check = map_check_begin(mpck, map->map);
	check = map_check_middle(mpck, map->map);
	check = map_check_end(mpck, map->map);
	check = map_checker_finalcheck(mpck);
	return (check);
}

char	*map_line(int fd)
{
	char	*str_gnl;
	char	*str;

	str = ft_calloc(1, sizeof(char));
	if (!str)
		ft_exit("malloc\nmalloc has failed!");
	str_gnl = get_next_line(fd);
	if (!str_gnl)
		ft_exit("malloc\nmalloc has failed!");
	while (str_gnl)
	{
		str = ft_strjoin(str, str_gnl);
		if (!str)
		{
			free(str);
			free(str_gnl);
			ft_exit("malloc\nmalloc has failed!");
		}
		str_gnl = get_next_line(fd);
		if (str_gnl && str_gnl[0] == '\n')
			ft_exit("map\nmap is invalid!");
	}
	if (str[0] == '\n' || str[0] == '\0')
		ft_exit("map\nmap is invalid!");
	free(str_gnl);
	return (str);
}
