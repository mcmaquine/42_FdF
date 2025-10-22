/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:33:52 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/22 15:42:12 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define ESC 65307
# define MOUSE_SCR_UP 4
# define MOUSE_SCR_DOWN 5
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_O 111
# define KEY_L 108
# define KEY_K 107

typedef struct s_color
{
	double	step_tpcy;
	double	step_r;
	double	step_g;
	double	step_b;
	double	tpcy;
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef	struct s_data
{
	int				abscissa;
	int				ordinate;
	int				**coord;
	unsigned int	**color;
}	t_data;

typedef struct s_canva
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_canva;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_matrix
{
	int		row;
	int		col;
	double	**a;
}	t_matrix;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_canva		canva;
	t_data		data;
	t_matrix	*current_tf;
	double		curr_scale_x;
	double		curr_scale_y;
	double		curr_scale_z;
	int			pan_x;
	int			pan_y;
}	t_window;

//utils
__uint32_t		atoi_16(char *ptr);
t_point			*new_point(int x, int y, int z, __uint32_t color);
void			*create_matrix(int rows, int cols);
void			free_matrix(t_matrix *m);
void			*copy_point(void *p);
void			*set_point(int x, int y, int z, unsigned int color);
void			edit_point(t_point *p, int x, int y, int z);
//draw functions
void			paint_pixel(t_window *w, int x, int y, unsigned int color);
void			*create_window(t_window *wind, int width, int height);
void			paint_canva_x(t_window *w, t_matrix *tf, int x, int y);
void			paint_canva_y(t_window *w, t_matrix *tf, int x, int y);
void			clear_canva(t_window *w);
void			line_draw(t_window *w, t_point *p0, t_point *p1);
void			draw_horizontal(t_window *w, t_point *p0, t_point *p1);
void			draw_vertical(t_window *w, t_point *p0, t_point *p1);
void			paint_line(t_window *w, t_point *p0, t_point *p1);
//file input validation
int				validate_file(int fd, int *rows);
void			validate_element(char **spl, int y, t_window *w);
int				read_points(char *file_name, t_window *w);
void			free_data(t_window *w);
// math utils
t_matrix		*mult_mat(t_matrix *a, t_matrix *b);
void			*mult_point_matrix(void *p, void *m);
void			*copy_matrix(void *m);
// transformation matrixes and scalings
t_matrix		*get_scale_mtx(double kx, double ky, double kz);
t_matrix		*get_rotate_mtx_x(double theta);
t_matrix		*get_rotate_mtx_y(double theta);
t_matrix		*get_rotate_mtx_z(double theta);
t_matrix		*get_isometric_mtx_tf(double orientation);
void			get_figure_center(t_window *w, t_matrix *tf, int *cx, int *cy);
double			get_max_scaling(t_window *w);
t_matrix		*get_dimetric_mtx_tf(void);
// window events
int				key_press_event(int keycode, t_window *w);
int				pan_event(int keycode, t_window *w);
int				on_close(t_window *w);
int				mouse_hook(int button, int x, int y, t_window *w);
void			scale_image(t_window *w);
void			rotate(t_window *w, double step);
//color utils
unsigned char	get_transparency(unsigned int color);
unsigned char	get_red(unsigned int color);
unsigned char	get_green(unsigned int color);
unsigned char	get_blue(unsigned int color);
unsigned int	set_color(int t, int r, int g, int b);
void			*init_color_step(t_point *p_st, t_point *p_end, int *dxdy);
unsigned int	get_step_color(t_color *c);
#endif
