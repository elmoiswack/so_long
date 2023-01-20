/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/01/20 23:00:17 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct map_check {
	int	p_count;
	int	e_count;
	int	c_count;
	int	x_max;
	int	y_max;
} t_mapcheck;

typedef struct map_path_check {
	int destination_x;
	int destination_y;
	int	p_x;
	int	p_y;
} t_pathcheck;

typedef struct s_images {
	void		*player;
	void		*exit;
	void		*coin;
	void		*walls;
	void		*floor;
	void		*chest;
}	t_image;

typedef struct s_map {
	char			**map;
	int				x;
	int				y;
	int				window_x;
	int				window_y;
	int				window_center_x;
	int				window_center_y;
	mlx_key_data_t	keydata;
	t_pathcheck		*phck;
	mlx_image_t		*mlx_image;
	mlx_t			*mlx;
	t_image			*image;
}	t_map;

//1 time functions
int		arg_checks(int argc, char *argv[]);
void	window_creation(t_map *map, t_mapcheck *mpck);
void	button_key_hook(void *param);

//globally used functions
void	ft_exit(char *str);
void	ft_free_2d_array(char **array, int y);

//valid map
char	**map_check_file(t_map *map, t_mapcheck *mpck, char **argv);
char	*map_line(int fd, char *str);
int		map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_begin(t_mapcheck *mpck, char **map_arr);
int		map_check_middle(t_mapcheck *mpck, char **map_arr);
int		map_check_end(t_mapcheck *mpck, char **map_arr);
int		map_checker_finalcheck(t_mapcheck *mpck);
//valid path in map
int		map_check_path(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_p(t_mapcheck *mpck, char **map_arr, t_pathcheck *phck);
char 	**map_copy_function(char **map_arr, t_mapcheck *mpck);
int		map_check_valid_path(t_pathcheck *phck, char **map_copy, int x, int y);

//images
void	images(t_map *map, t_mapcheck *mpck);
void	open_images(t_image *image);
void	texture_image(t_image *image, t_map *map);
void	image_window(t_image *image, char **map_arr, t_map *map, t_mapcheck *mpck);
void	place_floors_walls(t_image *image, char **map_arr, t_map *map, t_mapcheck *mpck);

#endif