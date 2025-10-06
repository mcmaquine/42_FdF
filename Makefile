NAME = fdf

INC=/usr/include

INCLIB=$(INC)/../lib

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC =	src/fdf.c\
		src/fdf_utils.c\
		src/fdf_utils_b.c\
		src/fdf_draw_util.c\
		src/fdf_file_validation.c\
		src/fdf_math.c\
		src/fdf_tlinear.c\
		src/fdf_events.c\
		src/fdf_scalings.c

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
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: re fclean clean all