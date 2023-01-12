/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:58 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/12 15:57:20 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	arg_checks(int argc, char *argv[])
{
	char	*str;
	int		index_1;
	int		index_2;
	
	index_1 = ft_strlen(argv[1]);
	index_1 -= 4;
	index_2 = 0;
	str = malloc(4 * sizeof(char));
	if (!str)
		ft_exit("malloc\nallocation failed in arg_checks!");
	ft_strlcpy(str, ".ber", 4);
	if (argc < 2)
		ft_exit("argc\nto few arguments!");
	if (argc > 2)
		ft_exit("argc\nto much arguments!");
	while (str[index_2])
	{
		if (str[index_2] != argv[1][index_1])
			ft_exit("argument\nthe map doesn't end with '.ber'!");
		index_1++;
		index_2++;
	}
	free(str);
	return (1);
}