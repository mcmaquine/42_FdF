/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:57:11 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/15 17:13:52 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	*set_point(int x, int y, int z, unsigned int color)
{
	t_point	*p;

	p = ft_calloc(1, sizeof(t_point));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = z;
	p->color = color;
	return (p);
}

void	edit_point(t_point *p, int x, int y, int z)
{
	if (!p)
		return ;
	p->x += x;
	p->y += y;
	p->z += z;
}

/*
Copy content from point p to a new point.
Returns a pointer to the new point.
*/
void	*copy_point(void *p)
{
	t_point	*copy;
	t_point	*point;

	if (!p)
		return (NULL);
	point = (t_point *)p;
	copy = ft_calloc(1, sizeof(t_point));
	if (!copy)
		return (NULL);
	copy->x = point->x;
	copy->y = point->y;
	copy->z = point->z;
	copy->color = point->color;
	return (copy);
}

void	free_point(void *p)
{
	free(p);
}

void	free_data(t_window *w)
{
	int	i;

	i = 0;
	while (i < w->data.ordinate)
	{
		free(w->data.coord[i]);
		free(w->data.color[i]);
		i++;
	}
	free(w->data.coord);
	free(w->data.color);
}
