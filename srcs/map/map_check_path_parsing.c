#include "../../so_long.h"

int		map_check_valid_path(t_pathcheck *phck, char **map_copy, int x, int y)
{
    if (x == phck->destination_x && y == phck->destination_y)
        return (1);
    map_copy[y][x] = '@';
    if (map_copy[y][x + 1] != '@' && map_copy[y][x + 1] != '1')
    {
        if (map_check_valid_path(phck, map_copy, x + 1, y) == 1)
            return (1);
    }
    if (map_copy[y][x - 1] != '@' && map_copy[y][x - 1] != '1')
    {
        if (map_check_valid_path(phck, map_copy, x - 1, y) == 1)
            return (1);
    }
    if (map_copy[y + 1][x] != '@' && map_copy[y + 1][x] != '1')
    {
        if (map_check_valid_path(phck, map_copy, x, y + 1) == 1)
            return (1);
    }
    if (map_copy[y - 1][x] != '@' && map_copy[y - 1][x] != '1')
    {
        if (map_check_valid_path(phck, map_copy, x, y - 1) == 1)
            return (1);
    }
    return (-1);
}