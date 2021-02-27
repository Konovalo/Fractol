
NAME = fractol
INCLUDES = -I./libft/ -I./minilibx_macos

CC = gcc
SRC =  fractol.c type_fractal.c color.c mouse_key.c
LIB_MLX = ./minilibx_macos/libmlx.a
LIB_FT = ./libft/libft.a 
OBJ = $(patsubst %.c, %.o, $(SRC))
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

.PHONY: lib all clean fclean re

all:	$(NAME)

%.o: %.c fractol.h
		$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIB_FT) $(LIB_MLX) $(OBJ)
		$(CC) -o $@ $(OBJ) -L./libft -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

libft_a:
		$(MAKE) -C ./libft

libmlx: 
		@$(MAKE) -C ./minilibx_macos

$(LIB_FT): libft_a

$(LIB_MLX): libmlx

clean:
		$(MAKE) -C ./libft/ clean
		$(MAKE) -C ./minilibx_macos/ clean
		rm -f $(OBJ)

fclean: clean
		$(MAKE) -C ./libft/ fclean
		rm -f $(NAME)

re: fclean $(NAME)
