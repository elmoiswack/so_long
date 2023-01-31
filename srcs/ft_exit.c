/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:00:04 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/12 11:47:25 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_exit(char *str, t_map *map)
{
	ft_printf("Error in %s\n", str);
	free_structmap(map);
	exit(EXIT_FAILURE);
}
