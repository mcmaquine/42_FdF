/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:21:47 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/09 17:41:20 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	update(int *error, int *start, int *d, int *step)
{
	*error = *error + *d;
	*start = *start + *step;
}

static int	init_step(int *start, int *end)
{
	if (*start < *end)
		return (1);
	else
		return (-1);
}

void lineDraw(t_window *w, t_point *p0, t_point *p1)
{
	int	dxdy[2];
	int	sx;
	int	sy;
	int	error[2];

	if (!p0 || !p1 || !w)
		return ;
	dxdy[0] = abs(p1->x - p0->x);
	dxdy[1] = -abs(p1->y - p0->y);
	sx = init_step(&(p0->x), &(p1->x));
	sy = init_step(&(p0->y), &(p1->y));
	error[0] = dxdy[0] + dxdy[1];
	while ((p0->x != p1->x) && (p0->y != p1->y))
	{
		paint_pixel(w, p0->x, p0->y, p0->color);
		error[1] = 2 * error[0];
		if (error[1] >= dxdy[1])
			update(&error[0], &(p0->x), &dxdy[1], &sx);
		if (error[1] <= dxdy[0])
			update(&error[0], &(p0->y), &dxdy[0], &sy);
	}
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
