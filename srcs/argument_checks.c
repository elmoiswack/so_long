/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:38:58 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/03 14:00:24 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	str_check(char *str, char *argv[], int index_1, int index_2)
{
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
	return (1);
}

int	arg_checks(int argc, char *argv[])
{
	char	*str;
	int		index_1;
	int		index_2;

	if (argc < 2)
		return (exit_printf("Error in arg_checks\ntoo few arguments!"));
	if (argc > 2)
		return (exit_printf("Error in arg_checks\ntoo much arguments!"));
	index_1 = ft_strlen(argv[1]);
	index_1 -= 4;
	index_2 = 0;
	str = malloc(4 * sizeof(char));
	if (!str)
		return (exit_printf("Error in arg_checks\nallocation failed of str!"));
	ft_strlcpy(str, ".ber", 4);
	if (str_check(str, argv, index_1, index_2) == -1)
		return (-1);
	free(str);
	return (1);
}
