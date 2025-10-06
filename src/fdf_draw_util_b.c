/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_util_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:21:47 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 18:26:30 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	error;

	if (!p0 || !p1 || !w)
		return ;
	dx = abs(p1->x - p0->x);
	dy = -abs(p1->y - p0->y);
	sx = init_step(p0->x, p1->x);
	sy = init_step(p0->y, p1->y);
	error = dx + dy;
	while ((p0->x != p1->x) && (p0->y != p1->y))
	{
		paint_pixel(w, p0->x, p0->y, p0->color);
		if ((2 * error) >= dy)
			update(&error, &(p0->x), &dy, &sx);
		if ((2 * error) <= dx)
			update(&error, &(p0->y), &dx, &sy);
	}
	free(p0);
	free(p1);
}
