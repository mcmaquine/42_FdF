/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:49:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/02 17:10:28 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*create_window(t_window *wind, int width, int height)
{
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, width, height, "FdF Canva");
	wind->width = width;
	wind->height = height;
	return (wind->mlx);
}

void	paint_pixel(t_window *w, int x, int y, unsigned int color)
{
	char	*dst;

	if (((x >= 0) && (x < w->width)) && ((y >= 0) && (y < w->height)))
	{
		dst = w->canva.addr + (y * w->canva.line_length
				+ x * (w->canva.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	clear_canva(t_window *w)
{
	int	x;
	int	y;

	x = -1;
	while (++x < w->width)
	{
		y = -1;
		while (++y < w->height)
			paint_pixel(w, x, y, 0);
	}
}

/*
Work in progress.
*/
void	paint_canva(t_window *w)
{
	t_list	*lst;
	t_point	*p;
	t_matrix	*m, *m2, *m3;

	lst = w->lpts;
	m = get_scale_mtx(50, 50, 20);
	m2 = get_isometric_mtx_tf();
	m3 = mult_mat(m, m2);
	while (lst)
	{
		p = mult_point_matrix((t_point *)lst->content, m3);
		p->color = ((t_point *)lst->content)->color;
		paint_pixel(w, p->x + 300, p->y + 100, p->color);
		free(p);
		lst = lst->next;
	}
	free_matrix(m);
	free_matrix(m2);
	free_matrix(m3);
}

/*
	Draw a circle centered on screen
	radius is in pixels.
void	draw_circle(int radius, t_window *wind)
{
	float	theta;
	float	dtheta = 2 * M_PI / wind->canva.line_length;
	int		x;
	int		y;
	
	theta = 0.0;
	while (theta < 2 * M_PI)
	{
		x = (int)radius * cos(theta);
		y = (int)radius * sin(theta);
		theta += dtheta;
		//x = x - wind->width/2;
		//y = wind->height/2 - y;
		paint_pixel(wind, x - wind->width/2, wind->height/2 - y, 0xFFFFFF);
		rotate_about_x(&y, 45*M_PI/180.0);
		paint_pixel(wind, x - wind->width/2, wind->height/2 - y, 0x007df9);
	}
}*/
