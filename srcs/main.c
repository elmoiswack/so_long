/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:59:57 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 16:28:57 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	main(int argc, char *argv[])
{
	t_map		*map;
	t_mapcheck	*mpck;

	mpck = ft_calloc(1, sizeof(t_mapcheck));
	if (!mpck)
		exit(EXIT_FAILURE);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		free(mpck);
		exit(EXIT_FAILURE);
	}
	if (arg_checks(argc, argv) == -1)
	{
		free(map);
		free(mpck);
		exit(EXIT_FAILURE);
	}
	map->map = map_check_file(map, mpck, argv);
	free(mpck);
	window_creation(map);
}
