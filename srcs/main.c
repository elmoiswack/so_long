/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:59:57 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/17 17:42:02 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	main(int argc, char *argv[])
{
	t_map		*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		ft_exit("malloc\nmalloc has failed in main!");
	arg_checks(argc, argv);
	map->map = map_check(argv, map);
	window_creation(map);
	exit(EXIT_SUCCESS);
}