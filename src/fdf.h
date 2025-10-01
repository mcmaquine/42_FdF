/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:57:33 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/01 16:43:13 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# define ESC 65307

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_data	canva;
	t_list	*lpts;
}	t_window;

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
	double 	**a;
}	t_matrix;

//utils
__uint32_t	atoi_16(char *ptr);
t_point		*new_point(int x, int y, int z, __uint32_t color);
t_matrix	*create_matrix(int rows, int cols);
void		free_matrix(t_matrix *m);
//draw functions
void		paint_pixel(t_window *w, int x, int y, int color);
void		*create_window(t_window *wind, int width, int height);
void		draw_circle(int radius, t_window *wind);
//data validation
int			validate_file(int fd);
void		validate_element(char **spl, int x, t_window *w);
int			read_points(char *file_name, t_window *w);
void		free_points(void *point);
//math
t_matrix	*matmul(t_matrix *a, t_matrix *b);
//linear transforms matrix functions
t_matrix	*get_scale_mtx(double kx, double ky, double kz);
t_matrix	*get_rotate_mtx_x(float theta);
t_matrix	*get_rotate_mtx_y(float theta);
t_matrix	*get_rotate_mtx_z(float theta);
t_matrix	*get_isometric_mtx_tf(void);
#endif
 