/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:58 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/18 15:02:39 by dhussain         ###   ########.fr       */
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
	{
		ft_printf("Error in arg_checks\nallocation failed of str!");
		return (-1);
	}
	ft_strlcpy(str, ".ber", 4);
	if (argc < 2)
	{
		free(str);
		ft_printf("Error in arg_checks\ntoo few arguments!");
		return (-1);
	}
	if (argc > 2)
	{
		free(str);
		ft_printf("Error in arg_checks\ntoo much arguments!");
		return (-1);
	}	
	while (str[index_2])
	{
		if (str[index_2] != argv[1][index_1])
		{
			free(str);
			ft_printf("Error in arg_checks\nmap doesn't end with .ber!");
			return (-1);
		}
		index_1++;
		index_2++;
	}
	free(str);
	return (1);
}
