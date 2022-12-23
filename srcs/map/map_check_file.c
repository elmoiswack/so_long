#include "../../so_long.h"

int	map_check_file(char **argv)
{
	int 	fd;
	int 	i;
	t_map	*map;
	t_mapcheck *mpck;
	char	*map_str;

	fd = open(argv[1], O_RDONLY);
	map = ft_calloc(1, sizeof(t_map));
	mpck = ft_calloc(1, sizeof(t_mapcheck));
	map_str = map_line(fd);
	close (fd);
	map->map = ft_split(map_str, '\n');
	i = map_check_begin(mpck, map->map);
	i = map_check_middle(mpck, map->map);
	i = map_check_end(mpck, map->map);
	i = map_checker_finalcheck(mpck);
	return (i);
}

char	*map_line(int fd)
{
	int	i;
	int	j;
	char	*str_gnl;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc(1, sizeof(char));
	str_gnl = get_next_line(fd);
	while (str_gnl)
	{
		str = ft_strjoin(str, str_gnl);
		str_gnl = get_next_line(fd);
	}
	if (str[0] == '\n' || str[0] == '\0')
		ft_exit("map, map is invalid!");
	return (str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
