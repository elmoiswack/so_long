/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/02/01 16:46:33 by dhussain         ###   ########.fr       */
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
	int	player_x;
	int	player_y;
	int	x_max;
	int	y_max;
}	t_mapcheck;

typedef struct map_path_check {
	int	destination_x;
	int	destination_y;
	int	p_x;
	int	p_y;
}	t_pathcheck;

typedef struct s_images {
	mlx_texture_t		*t_player;
	mlx_texture_t		*t_exit;
	mlx_texture_t		*t_coin;
	mlx_texture_t		*t_walls;
	mlx_texture_t		*t_floor;
	mlx_texture_t		*t_chest;
}	t_image;

typedef struct s_map {
	char			**map;
	int				moves;
	int				c_count;
	int				x;
	int				y;
	int				x_max;
	int				y_max;
	int				window_x;
	int				window_y;
	int				map_player_x;
	int				map_player_y;
	int				direction;
	mlx_texture_t	*map_t_player;
	mlx_image_t		*player;
	mlx_image_t		*exit;
	mlx_image_t		*coin;
	mlx_image_t		*walls;
	mlx_image_t		*floor;
	mlx_image_t		*chest;
	mlx_key_data_t	keydata;
	mlx_image_t		*mlx_image;
	mlx_t			*mlx;
	t_image			*image;
}	t_map;

//1 time functions
int		arg_checks(int argc, char *argv[]);
void	copy_variables(t_map *map, t_mapcheck *mpck);
void	window_creation(t_map *map);
int		get_window_size(t_map *map);
void	button_key_hook(void *param);
void	ending(t_map *map);
void	ending_failure(t_map *map);

//free and exit functions
void	ft_exit(char *str, t_map *map);
int		exit_printf(char *str);
void	ft_free_2d_array(char **array);
void	free_structmap(t_map *map);
void	texture_free(t_image *image);
void	free_checkers_failed(t_map *map, t_mapcheck *mpck, char *str);
void	free_mapcopy(char **map_copy, int y);

//valid map
char	**map_check_file(t_map *map, t_mapcheck *mpck, char **argv);
char	*map_line(int fd, char *str);
void	map_check_map(t_map *map, t_mapcheck *mpck);
void	copy_variables(t_map *map, t_mapcheck *mpck);
char	**map_check_final(t_map *map, t_mapcheck *mpck);
int		map_check_checker(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_begin(t_mapcheck *mpck, char **map_arr);
int		map_check_middle(t_mapcheck *mpck, char **map_arr);
int		map_check_end(t_mapcheck *mpck, char **map_arr);
int		map_checker_finalcheck(t_mapcheck *mpck);
//valid path in map
int		map_check_path(t_mapcheck *mpck, char **map_arr, int x, int y);
int		map_check_p(t_mapcheck *mpck, char **map_arr, t_pathcheck *phck);
char	**map_copy_function(char **map_arr, t_mapcheck *mpck);
int		map_check_valid_path(t_pathcheck *phck, char **map_copy, int x, int y);
int		path_checker(t_pathcheck *phck, t_mapcheck *mpck, char **map_copy);

//images
void	images(t_map *map);
int		open_images(t_image *image);
void	texture_image(t_image *image, t_map *map);
void	texture_walls_chests_floor(t_image *image, t_map *map);
void	image_window(char **map_arr, t_map *map);
void	place_floors_walls(char **map_arr, t_map *map);
void	player_recreation_right(t_map *map);
void	player_recreation_left(t_map *map);

//movement
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	checker_points_map(t_map *map);

#endif