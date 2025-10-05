/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scalings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:15:44 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/02 18:01:04 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_center(t_window *w, t_list *l, int *c_x, int *c_y)
{
	t_point	*p;
	t_list	*list;

	*c_x = 0;
	*c_y = 0;
	list = l;
	while (list)
	{
		p = list->content;
		if (((p->x >= 0) && (p->x < w->width)) 
				&& ((p->y >= 0) && (p->y < w->height)))
		{
			*c_x += p->x;
			*c_y += p->y;
		}
		list = list->next;
	}
	*c_x = *c_x / ft_lstsize(l);
	*c_y = *c_y / ft_lstsize(l); 
}

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
	t_list		*list;
	t_list		*l;
	t_point		*p;
	int			scaled;

	list = ft_lstmap(w->lpts, copy_point, free_points);
	l = list;
	while (l)
	{
		p = mult_point_matrix(((t_point *)l->content), tf);
		((t_point *)l->content)->x = p->x;
		((t_point *)l->content)->y = p->y;
		((t_point *)l->content)->z = p->z;
		free(p);
		l = l->next;
	}
	scaled = calc_max_scalings(w, list);
	ft_lstclear(&list, free_points);
	return (scaled);
}

void	get_figure_center(t_window *w, t_matrix *tf, int *c_x, int *c_y)
{
	t_list		*list;
	t_list		*l;
	t_point		*p;

	list = ft_lstmap(w->lpts, copy_point, free_points);
	l = list;
	while (l)
	{
		p = mult_point_matrix(((t_point *)l->content), tf);
		((t_point *)l->content)->x = p->x;
		((t_point *)l->content)->y = p->y;
		free(p);
		l = l->next;
	}
	calc_center(w, list, c_x, c_y);
	ft_lstclear(&list, free_points);
}
