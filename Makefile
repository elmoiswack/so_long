NAME	:=	so_long

HEADER 	:= so_long.h

MLX		:= ./mlx42

MLXLIB 	:= $(MLX)/libmlx42.a -I include -lglfw -L "/Users/dantehussain/.brew/opt/glfw/lib/" -fsanitize=address
#-lglfw3 -framework Cocoa -framework OpenGL -fsanitize=address -framework IOKit

LIBFT 		:= ./libft

LIBFTLIB	:= $(LIBFT)/libft.a

HEADERS	:=	-I $(LIBFT) -I includes -I $(MLX)/includes

SRC	:=	./srcs/main.c \
		./srcs/argument_checks.c \
		./srcs/map/map_check_file.c \
		./srcs/map/map_check_file_map.c \
		./srcs/map/map_check_path.c \
		./srcs/map/map_check_path_parsing.c \
		./srcs/ft_exit.c \
		./srcs/free_functions.c \
		./srcs/window.c \
		./srcs/sprites/images.c \
		./srcs/sprites/image_to_window.c \
		./srcs/sprites/open_images.c \
		./srcs/sprites/texture_to_image.c \
		./srcs/key_hook.c \
		./srcs/movement.c \
		./srcs/ending.c \


OBJ := $(SRC:.c=.o)

CC	:=	gcc

CFLAGS	:=	-g -Wall -Wextra -Werror

all: libs $(NAME)

libs:
	$(MAKE) -C libft
	$(MAKE) -C mlx42 DEBUG=1

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFTLIB) $(MLXLIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx42 clean

fclean:
	rm -f $(NAME) $(OBJ)
	$(MAKE) -C libft fclean
	$(MAKE) -C mlx42 fclean

re: fclean all

.PHONY: all clean fclean re