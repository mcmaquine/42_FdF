/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scalings_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:15:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/20 18:48:39 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	get_figure_center(t_window *w, t_matrix *tf, int *cx, int *cy)
{
	int		i;
	int		j;
	int		total;
	t_point	*p;
	t_point	*p0;

	i = -1;
	total = 0;
	while (++i < w->data.abscissa)
	{
		j = -1;
		while (++j < w->data.ordinate)
		{
			p0 = set_point(i, j, w->data.coord[j][i], 0);
			p = mult_point_matrix(p0, tf);
			*cx += p->x;
			*cy += p->y;
			total++;
			free(p);
			free(p0);
		}
	}
	*cx = *cx / total;
	*cy = *cy / total;
}

static void	*get_scaled_isometric()
{
	t_matrix	*sc;
	t_matrix	*iso;
	t_matrix	*product;

	sc = get_scale_mtx(10.0, 10.0, 4.0);
	iso = get_isometric_mtx_tf(0);
	product = mult_mat(iso, sc);
	free_matrix(sc);
	free_matrix(iso);
	return (product);
}

static void	scaling_compare(t_window *w, t_matrix *m, int *rng_x, int *rng_y)
{
	t_point	*p;
	t_point	*p0;
	int		i;
	int		j;

	i = -1;
	while (++i < w->data.abscissa)
	{
		j = -1;
		while (++j < w->data.ordinate)
		{
			p0 = set_point(i, j, w->data.coord[j][i], 0);
			p = mult_point_matrix(p0, m);
			if (p->x < rng_x[0])
				rng_x[0] = p->x;
			if (p->x > rng_x[1])
				rng_x[1] = p->x;
			if (p->y < rng_y[0])
				rng_y[0] = p->y;
			if (p->y > rng_y[1])
				rng_y[1] = p->y;
			free(p);
			free(p0);
		}
	}
}

double	get_max_scaling(t_window *w)
{
	int			range_x[2];
	int			range_y[2];
	t_matrix	*m;

	range_x[0] = w->data.coord[0][0];
	range_x[1] = range_x[0];
	range_y[0] = range_x[0];
	range_y[1] = range_y[0];
	m = get_scaled_isometric();
	scaling_compare(w, m, range_x, range_y);
	range_x[0] = (double)(w->width / (range_x[1] - range_x[0]));
	range_y[0] = (double)(w->height / (range_y[1] - range_y[0]));
	free_matrix(m);
	if (range_x[0] > range_y[0])
		range_x[0] = range_y[0];
	if (range_x[0] > 5.0)
		return (range_x[0] * 10);
	else
		return (5.0);
}