NAME	:=	so_long

HEADER 	:= so_long.h

MLX		:= ./mlx42

MLXLIB 	:= $(MLX)/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -fsanitize=address -framework IOKit

LIBFT 		:= ./libft

LIBFTLIB	:= $(LIBFT)/libft.a

HEADERS	:=	-I $(LIBFT) -I includes -I $(MLX)/includes

SRC	:=	./srcs/main.c \
		./srcs/map/map_check.c \
		./srcs/map/map_check_file.c \
		./srcs/map/map_check_file_map.c \
		./srcs/map/map_check_path.c \
		./srcs/map/map_check_path_parsing.c \
		./srcs/ft_exit.c \

OBJ := $(SRC:.c=.o)

CC	:=	gcc

CFLAGS	:=	-Wall -Wextra -Werror

libs:
	$(MAKE) -C libft
	$(MAKE) -C mlx42 DEBUG=1

$(NAME): $(OBJ)
	$(CC) $^ $(LIBFTLIB) $(MLXLIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: libs $(NAME) 

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