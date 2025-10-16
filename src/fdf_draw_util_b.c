/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:21:47 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/16 17:35:27 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	*init_color_step(t_point *p_st, t_point *p_end, int *dxdy)
{
	t_color	*clr;
	int		dx;
	int		dy;

	clr = ft_calloc(1, sizeof(t_color));
	dx = abs(dxdy[0]);
	dy = abs(dxdy[1]);
	if (dx < dy)
		dx = dy;
	clr->tpcy = get_transparency(p_st->color);
	clr->red = get_red(p_st->color);
	clr->green = get_green(p_st->color);
	clr->blue = get_blue(p_st->color);
	clr->tpcy = (double)(get_transparency(p_end->color)
			- get_transparency(p_st->color)/dx);
	clr->step_r = (double)(get_red(p_end->color) - get_red(p_st->color))/dx;
	clr->step_g = (double)(get_green(p_end->color) - get_green(p_st->color))/dx;
	clr->step_b = (double)(get_blue(p_end->color) - get_blue(p_st->color))/dx;
	return (clr);
}

static unsigned int	get_step_color(t_color *c)
{
	int				transparency;
	int				red;
	int				green;
	int				blue;
	unsigned int	color;

	c->tpcy += c->step_tpcy;
	c->red += c->step_r;
	c->green += c->step_g;
	c->blue += c->step_b;
	transparency = (int)c->tpcy;
	red = (int)c->red;
	green = (int)c->green;
	blue = (int)c->blue;
	color = set_color(transparency, red, green, blue);
	return (color);
}

static void	update(int *error, int *start, int *d, int *step)
{
	*error = *error + *d;
	*start = *start + *step;
}

static int	init_step(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

void lineDraw(t_window *w, t_point *p0, t_point *p1)
{
	int		dxdy[2];
	int		sxsy[2];
	int		error[2];
	t_color	*c;

	if (!p0 || !p1 || !w)
		return ;
	dxdy[0] = abs(p1->x - p0->x);
	dxdy[1] = -abs(p1->y - p0->y);
	sxsy[0] = init_step(p0->x, p1->x);
	sxsy[1] = init_step(p0->y, p1->y);
	error[0] = dxdy[0] + dxdy[1];
	c = init_color_step(p0, p1, dxdy);
	while ((p0->x != p1->x) && (p0->y != p1->y))
	{
		paint_pixel(w, p0->x, p0->y, get_step_color(c));
		error[1] = 5 * error[0];
		if (error[1] >= dxdy[1])
			update(&error[0], &(p0->x), &dxdy[1], &sxsy[0]);
 		if (error[1] <= dxdy[0])
			update(&error[0], &(p0->y), &dxdy[0], &sxsy[1]);
	}
	free(c);
	free(p0);
	free(p1);
}

/*
Clear canva writing color black on every pixel.
*/
void	clear_canva(t_window *w)
{
	int		x;
	int		y;

	x = -1;
	while (++x < w->width)
	{
		y = -1;
		while (++y < w->height)
			paint_pixel(w, x, y, 0);
	}
}
