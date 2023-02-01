/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 05:03:33 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 10:19:26 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ending(t_map *map)
{
	free_structmap(map);
	mlx_terminate(map->mlx);
	ft_printf("CONGRATS YOU COMPLETED THE MAP!!!!!\n");
	exit(EXIT_SUCCESS);
}
