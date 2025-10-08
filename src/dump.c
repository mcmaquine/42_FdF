/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:11:28 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/08 10:12:38 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
This file have functions that is not used anymore
*/
static int	calc_max_scalings(t_window *w, t_list *l)
{
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;

	min_x = ((t_point *)l->content)->x;
	min_y = ((t_point *)l->content)->y;
	max_x = min_x;
	max_y = min_y;
	while (l)
	{
		if (min_x > ((t_point *)l->content)->x)
			min_x = ((t_point *)l->content)->x;
		if (max_x < ((t_point *)l->content)->x)
			max_x = ((t_point *)l->content)->x;
		if (min_y > ((t_point *)l->content)->y)
			min_y = ((t_point *)l->content)->y;
		if (max_y < ((t_point *)l->content)->y)
			max_y = ((t_point *)l->content)->x;
		l = l->next;
	}
	if ((w->width / (max_x - min_x)) < (w->height / (max_y - min_y)))
		return (w->width / (max_x - min_x));
	else
		return (w->height / (max_y - min_y));
}

/*
	Get max scale factor for axis x, y, z to fit figure entirely on screen.
*/
int	get_max_scalings(t_window *w, t_matrix *tf)
{
	t_point		*p;
	t_point		*p0;
	int			scaled;
	int			i;
	int			j;

	i = -1;
	while (++i < w->data.abscissa)
	{
		j = -1;
		while (++j < w->data.ordinate)
		{
			p0 = set_point(i, j, w->data.coord[i][j], 0);
		}
	}
	scaled = calc_max_scalings(w, list);
	return (scaled);
}