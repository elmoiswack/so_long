/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:09 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/30 14:00:32 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	map_check(char **argv)
{
	int			i;
	char		**map_arr;
	t_pathcheck *phck;
	t_map		*map;
	t_mapcheck	*mpck;
	
	phck = ft_calloc(1, sizeof(t_pathcheck));
	if (!phck)
		ft_exit("malloc\nmalloc has failed!");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit("malloc\nmalloc has failed!");
	mpck = ft_calloc(1, sizeof(t_mapcheck));
	if (!mpck)
		ft_exit("malloc\nmalloc has failed!");
	map_arr = map_check_file(map, mpck, argv);
	i = map_check_path(phck, mpck, map_arr);
	return (i);
}
