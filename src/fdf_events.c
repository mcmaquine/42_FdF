/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:33:02 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/02 12:42:14 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	scale_image(t_window *w)
{
	int			x;
	int			y;
	t_matrix	*scaled;
	t_matrix	*tf;

	scaled = get_scale_mtx(w->curr_scale, w->curr_scale, 1);
	tf = mult_mat(scaled, w->current_tf);
	get_figure_center(w, tf, &x, &y);
	paint_canva(w, tf, x, y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	free_matrix(scaled);
	free_matrix(tf);
}

static void	free_memory(t_window *w)
{
	ft_lstclear(&(w->lpts), free_points);
	free_matrix(w->current_tf);
	mlx_destroy_image(w->mlx, w->canva.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
}

int	key_press_event(int keycode, t_window *w)
{
	if (keycode == ESC)
		on_close(w);
	return (0);
}

int	on_close(t_window *w)
{
	free_memory(w);
	exit(0);
	return (0);
}

/*
Function to handle mouse events
*/
int	mouse_hook(int button, int x, int y, t_window *w)
{
	(void)x;
	(void)y;
	clear_canva(w);
	if (button == MOUSE_SCR_DOWN)
	{
		w->curr_scale *= 0.9;
		scale_image(w);
	}
	if (button == MOUSE_SCR_UP)
	{
		w->curr_scale *= 1.1;
		scale_image(w);
	}
	return (0);
}
