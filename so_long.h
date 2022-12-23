#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct map_check {
	int p_count;
	int e_count;
	int c_count;
	int x_max;
	int	y_max;
} t_mapcheck;

typedef struct s_map {
	char	**map;
}	t_map;

//globally used files
void	ft_exit(char *str);

//entire map check
int	map_check(char **argv);

//valid map
int		map_check_file(char **argv);
char	*map_line(int fd);
int		map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_begin(t_mapcheck *mpck, char **map_arr);
int		map_check_middle(t_mapcheck *mpck, char **map_arr);
int		map_check_end(t_mapcheck *mpck, char **map_arr);
int		map_checker_finalcheck(t_mapcheck *mpck);
char	*ft_strcpy(char *dest, const char *src);


#endif