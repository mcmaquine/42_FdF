/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:57:11 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 19:38:28 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*search_next_vertical(t_window *w, int index, int fixed)
{
	t_list	*l;
	t_point	*p;

	l = w->lpts;
	p = NULL;
	while (l)
	{
		if (((t_point *)l->content)->x == fixed
				&& ((t_point *)l->content)->y == index)
		{
			p = ((t_point *)l->content);
			break ;
		}
		l = l->next;
	}
	return (p);
}

t_point	*search_next_horizontal(t_window *w, int index, int fixed)
{
	t_list	*l;
	t_point	*p;

	l = w->lpts;
	p = NULL;
	while (l)
	{
		if (((t_point *)l->content)->x == index
				&& ((t_point *)l->content)->y == fixed)
		{
			p = ((t_point *)l->content);
			break ;
		}
		l = l->next;
	}
	return (p);
}

/*
Return 2 points p0 and p1 if they have same x.
*/
void	get_two_points_horizontal(t_window *w, t_point **p0, t_point **p1)
{
	static int	ordinate;
	static int	abscissa;

	*p0 = search_next_horizontal(w, abscissa, ordinate);
	if (*p0)
		abscissa++;
	*p1 = search_next_horizontal(w, abscissa, ordinate);
	if (!(*p1))
	{
		abscissa = 0;
		ordinate++;
	}
	if (!(*p0) && !(*p1))
	{
		abscissa = 0;
		ordinate = 0;
	}
}

void	get_two_points_vertical(t_window *w, t_point **p0, t_point **p1)
{
	static int	ordinate;
	static int	abscissa;

	*p0 = search_next_vertical(w, ordinate, abscissa);
	if (*p0)
		ordinate++;
	*p1 = search_next_vertical(w, ordinate, abscissa);
	if (!(*p1))
	{
		abscissa++;
		ordinate = 0;
	}
	if (!(*p0) && !(*p1))
	{
		abscissa = 0;
		ordinate = 0;
	}
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
