/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:59:57 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/12 12:05:34 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int32_t	main(int argc, char *argv[])
{
	char	**map_arr;
	int		y;

	y = 0;
	if (argc != 2)
		return (0);
	map_arr = map_check(argv);
	while (map_arr[y])
	{
		ft_printf("%s\n", map_arr[y]);
		y++;
	}
	return (0);
}
