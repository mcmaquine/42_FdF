/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:29:10 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/01 17:02:14 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*matmul(t_matrix *a, t_matrix *b)
{
	t_matrix	*c;
	int			i;
	int			j;
	int			k;
	
	if (!a || !b)
		return (NULL);
	if (a->col != b->row)
		return (NULL);
	c = create_matrix(a->row, b->col);
	if (!c)
		return (c);
	i = -1;
	while (++i < a->row)
	{
		j = -1;
		while (++j < b->col)
		{
			k = -1;
			while (++k < a->col)
				c->a[i][j] += a->a[i][k] * b->a[k][j];
		}
	}
	return (c);
}

t_point	*point_matrix_mult(t_point *p, t_matrix *m)
{
	t_point	*calc_p;
	
	if (!p || !m)
		return (NULL);
	if (m->col != 3)
		return (NULL);
	calc_p = ft_calloc(1, sizeof(t_point));
	if (!calc_p)
		return (NULL);
	calc_p->x = p->x * m->a[0][0] + p->y * m->a[1][0] + p->y * m->a[2][0];
	calc_p->y = p->x * m->a[0][1] + p->y * m->a[1][1] + p->y * m->a[2][1];
	calc_p->z = p->x * m->a[0][2] + p->y * m->a[1][2] + p->y * m->a[2][2];
	return (calc_p);
}
