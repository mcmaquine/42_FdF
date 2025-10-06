/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:57:33 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 20:05:14 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	__uint32_t	color;
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
	t_data		canva;
	t_list		*lpts;
	t_matrix	*current_tf;
	double		curr_scale;
	int			pan_x;
	int			pan_y;
}	t_window;

//utils
__uint32_t	atoi_16(char *ptr);
t_point		*new_point(int x, int y, int z, __uint32_t color);
void		*create_matrix(int rows, int cols);
void		free_matrix(t_matrix *m);
void		*copy_point(void *p);
//draw functions
void		paint_pixel(t_window *w, int x, int y, unsigned int color);
void		*create_window(t_window *wind, int width, int height);
void		paint_canva_x(t_window *w, t_matrix *tf, int x, int y);
void		paint_canva_y(t_window *w, t_matrix *tf, int x, int y);
void		clear_canva(t_window *w);
void		lineDraw(t_window *w, t_point *p0, t_point *p1);
void		get_two_points_horizontal(t_window *w, t_point **p0, t_point **p1);
void		get_two_points_vertical(t_window *w, t_point **p0, t_point **p1);
//file input validation
int			validate_file(int fd);
void		validate_element(char **spl, int y, t_window *w);
int			read_points(char *file_name, t_window *w);
void		free_points(void *point);
// math utils
t_matrix	*mult_mat(t_matrix *a, t_matrix *b);
void		*mult_point_matrix(void *p, void *m);
void		*copy_matrix(void *m);
// transformation matrixes and scalings
t_matrix	*get_scale_mtx(double kx, double ky, double kz);
t_matrix	*get_rotate_mtx_x(double theta);
t_matrix	*get_rotate_mtx_y(double theta);
t_matrix	*get_rotate_mtx_z(double theta);
t_matrix	*get_isometric_mtx_tf(void);
int			get_max_scalings(t_window *w, t_matrix *tf);
void		get_figure_center(t_window *w, t_matrix *tf, int *c_x, int *c_y);
// window events
int			key_press_event(int keycode, t_window *w);
int			pan_event(int keycode, t_window *w);
int			on_close(t_window *w);
int			mouse_hook(int button, int x, int y, t_window *w);
#endif
