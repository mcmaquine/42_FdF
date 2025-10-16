/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scalings_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:15:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/15 17:13:29 by mmaquine         ###   ########.fr       */
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
