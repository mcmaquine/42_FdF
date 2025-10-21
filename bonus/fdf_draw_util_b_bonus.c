/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util_b_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:21:47 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/20 18:46:27 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	draw_horizontal(t_window *w, t_point *p0, t_point *p1)
{
	t_color	*c;
	int		dxdy[2];
	int		step;

	dxdy[0] = abs(p1->x - p0->x);
	dxdy[1] = dxdy[0];
	c = init_color_step(p0, p1, dxdy);
	step = init_step(p0->x, p1->x);
	while (p0->x != p1->x)
	{
		paint_pixel(w, p0->x, p0->y, get_step_color(c));
		p0->x += step;
	}
	free(c);
	free(p0);
	free(p1);
}

void	draw_vertical(t_window *w, t_point *p0, t_point *p1)
{
	t_color	*c;
	int		dxdy[2];
	int		step;

	dxdy[0] = abs(p1->y - p0->y);
	dxdy[1] = dxdy[0];
	c = init_color_step(p0, p1, dxdy);
	step = init_step(p0->y, p1->y);
	while (p0->y != p1->y)
	{
		paint_pixel(w, p0->x, p0->y, get_step_color(c));
		p0->y += step;
	}
	free(c);
	free(p0);
	free(p1);
}

void line_draw(t_window *w, t_point *p0, t_point *p1)
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
