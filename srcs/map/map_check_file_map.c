#include "../../so_long.h"

int	map_check_begin(t_mapcheck *mpck, char **map_arr)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (map_arr[y][x])
	{
		if (map_arr[y][x] != '1')
			ft_exit("map, upper border is invalid!");
		x++;
	}
	mpck->x_max = x;
	return (1);
}

int	map_check_middle(t_mapcheck *mpck, char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map_arr[mpck->y_max])
		mpck->y_max++;
	mpck->y_max = mpck->y_max - 1;
	while (y < mpck->y_max)
	{
		while (map_arr[y][x])
		{
			map_check_checker(mpck, map_arr, x, y);
			x++;
		}
		if (x != mpck->x_max)
			ft_exit("map, the map isnt the same size!");
		y++;
		x = 0;
	}
	return (1);
}

int	map_check_end(t_mapcheck *mpck, char **map_arr)
{
	int	x;

	x = 0;
	while (map_arr[mpck->y_max][x])
	{
		if (map_arr[mpck->y_max][x] != '1')
			ft_exit("map, lower border is invalid!");
		x++;
	}
	if (x != mpck->x_max)
		ft_exit("map, the map isnt the same size!");
	return (1);
}

int	map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y)
{
	if ((map_arr[y][0] != '1') || (map_arr[y][mpck->x_max - 1] != '1'))
		ft_exit("map, border left or right is invalid!");
	else if (map_arr[y][x] == 'P')
	{
		mpck->p_count += 1;
		return (1);
	}
	else if (map_arr[y][x] == 'E')
	{
		mpck->e_count += 1;
		return (1);
	}
	else if (map_arr[y][x] == 'C')
	{
		mpck->c_count += 1;
		return (1);
	}
	else if (map_arr[y][x] == '0' || map_arr[y][x] == '1')
		return (1);
	ft_exit("map, stop adding random stuff!");
	return (-1);
}

int	map_checker_finalcheck(t_mapcheck *mpck)
{	
	if (mpck->e_count < 1)
		ft_exit("map, no exit found!");	
	if (mpck->e_count > 1)
		ft_exit("map, too many exit found!");	
	if (mpck->p_count < 1)
		ft_exit("map, no start found!");
	if (mpck->p_count > 1)
		ft_exit("map, too many start found!");
	if (mpck->c_count < 1)
		ft_exit("map, no collictibles found!");
	return (1);
}