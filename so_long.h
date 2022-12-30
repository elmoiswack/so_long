#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_map {
	char	**map;
}	t_map;

typedef struct map_check {
	int	p_count;
	int	e_count;
	int	c_count;
	int	x_max;
	int	y_max;
} t_mapcheck;

typedef struct map_path_check {
	int	p_x;
	int	p_y;
	int	checkpoint_x;
	int	checkpoint_y;
	int	temp_x;
	int	temp_y;
	int directions;
} t_pathcheck;

//globally used functions
void	ft_exit(char *str);

//entire map check
int		map_check(char **argv);

//valid map
char	**map_check_file(t_map *map, t_mapcheck *mpck, char **argv);
char	*map_line(int fd);
int		map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_begin(t_mapcheck *mpck, char **map_arr);
int		map_check_middle(t_mapcheck *mpck, char **map_arr);
int		map_check_end(t_mapcheck *mpck, char **map_arr);
int		map_checker_finalcheck(t_mapcheck *mpck);

//valid path
int		map_check_path(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
void	map_check_path_xplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
void	map_check_path_xmin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
void	map_check_path_yplus(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
void	map_check_path_ymin(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
int		map_check_path_setcheckpoint(t_pathcheck *phck, char **map_arr);
void 	map_check_path_resetxy(t_pathcheck *phck);
int		map_check_path_points(t_pathcheck *phck, t_mapcheck *mpck, char **map_arr);
int		find_start_point(t_pathcheck *phck, char **map_arr);

#endif