/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:33:02 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/22 20:44:20 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale_image(t_window *w)
{
	t_matrix	*scaled;
	t_matrix	*tf;
	t_matrix	*mult;

	clear_canva(w);
	scaled = get_scale_mtx(w->curr_scale_x, w->curr_scale_y,
			0.4 * w->curr_scale_z);
	tf = w->tf(w->orient);
	mult = mult_mat(scaled, tf);
	paint_canva_x(w, mult, w->pan_x, w->pan_y);
	paint_canva_y(w, mult, w->pan_x, w->pan_y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	free_matrix(scaled);
	free_matrix(tf);
	free_matrix(mult);
}

static void	free_memory(t_window *w)
{
	free_data(w);
	mlx_destroy_image(w->mlx, w->canva.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
}

int	key_press_event(int keycode, t_window *w)
{
	if (keycode == ESC)
		on_close(w);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		if (keycode == KEY_RIGHT)
			w->orient += .2;
		else
			w->orient -= .2;
		rotate(w);
	}
	else if (keycode == KEY_O || keycode == KEY_L)
	{
		if (keycode == KEY_O)
			w->curr_scale_z *= 1.1;
		else
			w->curr_scale_z *= 0.9;
		scale_image(w);
	}
	else if (keycode == KEY_K)
		change_view(w);
	else
		pan_event(keycode, w);
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
		w->curr_scale_x *= 0.9;
		w->curr_scale_y *= 0.9;
		w->curr_scale_z *= 0.9;
		scale_image(w);
	}
	if (button == MOUSE_SCR_UP)
	{
		w->curr_scale_x *= 1.1;
		w->curr_scale_y *= 1.1;
		w->curr_scale_z *= 1.1;
		scale_image(w);
	}
	return (0);
}
