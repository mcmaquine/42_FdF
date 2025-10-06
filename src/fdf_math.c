/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:29:10 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 16:51:43 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Multiply two matrixes.
Returns matrix product of the operatrion. NULL if operations not possible.
*/
t_matrix	*mult_mat(t_matrix *a, t_matrix *b)
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

/*
Execute a product of a point p with a matrix m
Returns the product.
*/
void	*mult_point_matrix(void *p, void *m)
{
	t_point		*cp;
	t_point		*pnt;
	t_matrix	*mat;

	if (!p || !m)
		return (NULL);
	mat = m;
	pnt = p;
	if (mat->col != 3)
		return (NULL);
	cp = ft_calloc(1, sizeof(t_point));
	if (!cp)
		return (NULL);
	cp->x = (int )(pnt->x * mat->a[0][0] + pnt->y * mat->a[1][0]
			+ pnt->z * mat->a[2][0]);
	cp->y = (int )(pnt->x * mat->a[0][1] + pnt->y * mat->a[1][1]
			+ pnt->z * mat->a[2][1]);
	cp->z = (int )(pnt->x * mat->a[0][2] + pnt->y * mat->a[1][2]
			+ pnt->z * mat->a[2][2]);
	cp->color = pnt->color;
	return (cp);
}

/*
Copy a t_matrix m.
Return a copy of t_matrix m.
*/
void	*copy_matrix(void *m)
{
	t_matrix	*copy;
	t_matrix	*mat;
	int			i;
	int			j;

	if (!m)
		return (NULL);
	mat = (t_matrix *)m;
	copy = create_matrix(mat->row, mat->col);
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < mat->row)
	{
		j = -1;
		while (++j < mat->col)
			copy->a[i][j] = mat->a[i][j];
	}
	return (copy);
}
