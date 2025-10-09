/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:49:56 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/09 16:43:13 by mmaquine         ###   ########.fr       */
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
Work in progress.
*/
void	paint_canva_x(t_window *w, t_matrix *tf, int x, int y)
{
	t_point	*p0;
	t_point	*p1;
	t_point	*p0tf;
	t_point	*p1tf;
	int		yx[2];

	yx[0] = -1;
	while (++yx[0] < w->data.ordinate)
	{
		yx[1] = -1;
		while (++yx[1] < w->data.abscissa - 1)
		{
			p0 = set_point(yx[1], yx[0], w->data.coord[yx[0]][yx[1]], w->data.color[yx[0]][yx[1]]);
			p1 = set_point(yx[1] + 1, yx[0], w->data.coord[yx[0]][yx[1] + 1], w->data.color[yx[0]][yx[1] + 1]);
 			p0tf = mult_point_matrix(p0, tf);
			p1tf = mult_point_matrix(p1, tf);
			edit_point(p0tf, w->width/2 - x, w->height/2 - y, 0);
			edit_point(p1tf, w->width/2 - x, w->height/2 - y, 0);
			lineDraw(w, p0tf, p1tf);
			free(p0);
			free(p1);
		}
	}
}

void	paint_canva_y(t_window *w, t_matrix *tf, int x, int y)
{
	t_point	*p0;
	t_point	*p1;
	t_point	*p0tf;
	t_point	*p1tf;
	int		yx[2];

	yx[1] = -1;
	while (++yx[1] < w->data.abscissa)
	{
		yx[0] = -1;
		while (++yx[0] < w->data.ordinate - 1)
		{
			p0 = set_point(yx[1], yx[0], w->data.coord[yx[0]][yx[1]],
					w->data.color[yx[0]][yx[1]]);
			p1 = set_point(yx[1], yx[0] + 1, w->data.coord[yx[0] + 1][yx[1]],
					w->data.color[yx[0] + 1][yx[1]]);
			p0tf = mult_point_matrix(p0, tf);
			p1tf = mult_point_matrix(p1, tf);
			edit_point(p0tf, w->width/2 - x, w->height/2 - y, 0);
			edit_point(p1tf, w->width/2 - x, w->height/2 - y, 0);
 			lineDraw(w, p0tf, p1tf);
			free(p0);
			free(p1);
		}
	}
}

void	paint_linear(t_window *w, t_point *p0, t_point *p1)
{
	static char	step_r;
	static char	step_g;
	static char	step_b;

	if ((p0->x == p1->x) && (p0->y == p1->y))
	{
		step_r = 0;
		step_g = 0;
		step_b = 0;
		paint_pixel(w, p0->x, p0->y, p1->color);
	}
}
