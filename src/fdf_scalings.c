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

/*
	Get max scale factor for axis x, y, z to fit figure entirely on screen.
*/
int	get_max_scalings(t_window *w)
{
	t_list		*list;
	t_list		*l;

	list = ft_lstmap(w->lpts, copy_matrix, free_points);
	l = list;
	while (l)
	{
		ft_printf("%d %d %d\n", ((t_point *)l->content)->x, ((t_point *)l->content)->y, ((t_point *)l->content)->z);
		l = l->next;
	}
	ft_lstclear(&list, free_points);
	return (0);
}
/*
void	get_figure_center(t_window *w, int *x, int *y)
{
	
}*/
