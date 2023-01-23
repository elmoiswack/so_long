/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:59:57 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/23 14:27:49 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	main(int argc, char *argv[])
{
	t_map		*map;
	t_mapcheck	*mpck;

	mpck = ft_calloc(1, sizeof(t_mapcheck));
	if (!mpck)
		ft_exit("malloc\nmalloc has failed map_check!");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit("malloc\nmalloc has failed in main!");
	arg_checks(argc, argv);
	map->map = map_check_file(map, mpck, argv);
	window_creation(map, mpck);
	exit(EXIT_SUCCESS);
}
