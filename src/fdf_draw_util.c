/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:49:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 19:16:31 by mmaquine         ###   ########.fr       */
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

/*
Clear canva writing color black on every pixel.
*/
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
void	paint_canva_x(t_window *w, t_matrix *tf, int x, int y)
{
	t_point	*p0;
	t_point	*p1;
	t_point	*p0tf;
	t_point	*p1tf;

	p0 = NULL;
	p1 = NULL;
	get_two_points_horizontal(w, &p0, &p1);
	while (p0 || p1)
	{
		p0tf = mult_point_matrix(p0, tf);
		p1tf = mult_point_matrix(p1, tf);
		if (p0tf && p1tf)
		{
			p0tf->x += p0tf->x + w->width/2 - x;
			p0tf->y += p0tf->y + w->height/2 - y;
			p1tf->x += p1tf->x + w->width/2 - x;
			p1tf->y += p1tf->y + w->height/2 - y;
			lineDraw(w, p0tf, p1tf);
		}
		get_two_points_horizontal(w, &p0, &p1);
	}
}

void	paint_canva_y(t_window *w, t_matrix *tf, int x, int y)
{
	t_point	*p0;
	t_point	*p1;
	t_point	*p0tf;
	t_point	*p1tf;

	p0 = NULL;
	p1 = NULL;
	get_two_points_vertical(w, &p0, &p1);
	while (p0 || p1)
	{
		p0tf = mult_point_matrix(p0, tf);
		p1tf = mult_point_matrix(p1, tf);
		if (p0tf && p1tf)
		{
			p0tf->x += p0tf->x + w->width/2 - x;
			p0tf->y += p0tf->y + w->height/2 - y;
			p1tf->x += p1tf->x + w->width/2 - x;
			p1tf->y += p1tf->y + w->height/2 - y;
			lineDraw(w, p0tf, p1tf);
		}
		get_two_points_vertical(w, &p0, &p1);
	}
}
