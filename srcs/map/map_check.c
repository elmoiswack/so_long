/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:09 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/12 13:27:23 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**map_check(char **argv)
{
	char		**map_arr;
	t_map		*map;
	t_mapcheck	*mpck;
	
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit("malloc\nmalloc has failed in map_check!");
	mpck = ft_calloc(1, sizeof(t_mapcheck));
	if (!mpck)
		ft_exit("malloc\nmalloc has failed map_check!");
	map_arr = map_check_file(map, mpck, argv);
	return (map_arr);
}
