NAME = fdf

INC=/usr/include

INCLIB=$(INC)/../lib

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRC =	src/fdf.c\
		src/fdf_color_util.c\
		src/fdf_color_step.c\
		src/fdf_utils.c\
		src/fdf_utils_a.c\
		src/fdf_draw_util.c\
		src/fdf_draw_util_b.c\
		src/fdf_file_validation.c\
		src/fdf_math.c\
		src/fdf_tlinear_util.c\
		src/fdf_tlinear.c\
		src/fdf_events.c\
		src/fdf_scalings.c

BONUS = bonus/fdf_bonus.c\
		bonus/fdf_color_util_bonus.c\
		bonus/fdf_color_step_bonus.c\
		bonus/fdf_utils_bonus.c\
		bonus/fdf_utils_a_bonus.c\
		bonus/fdf_draw_util_bonus.c\
		bonus/fdf_draw_util_b_bonus.c\
		bonus/fdf_file_validation_bonus.c\
		bonus/fdf_math_bonus.c\
		bonus/fdf_tlinear_util_bonus.c\
		bonus/fdf_tlinear_bonus.c\
		bonus/fdf_events_bonus.c\
		bonus/fdf_events_a_bonus.c\
		bonus/fdf_scalings_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

LFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(NAME)_bonus

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	cc $^ -o $@ $(LFLAGS)

$(NAME)_bonus: $(OBJ_BONUS) $(LIBFT) $(MLX)
	cc $^ -o $@ $(LFLAGS)
	mv $@ $(NAME)
 
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX):
	$(MAKE) -C $(MLX_DIR) all

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: re fclean clean all