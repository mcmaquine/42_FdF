NAME = fdf

INC=/usr/include

INCLIB=$(INC)/../lib

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC = fdf.c fdf_utils.c fdf_draw_util.c fdf_file_validation.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	cc $^ -o $@ $(LFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	$(MAKE) -C $(MLX_DIR) all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: re fclean clean all