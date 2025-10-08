/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scalings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:15:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/08 18:29:56 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_figure_center(t_window *w, t_matrix *tf, int *c_x, int *c_y)
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
			*c_x += p->x;
			*c_y += p->y;
			total++;
			free(p);
			free(p0);
		}
	}
	*c_x = *c_x / total;
	*c_y = *c_y / total;
}
