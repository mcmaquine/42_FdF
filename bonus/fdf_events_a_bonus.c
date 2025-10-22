/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:57:35 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/22 20:43:08 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	pan_event(int keycode, t_window *w)
{
	clear_canva(w);
	if (keycode == KEY_W)
		w->pan_y += 10;
	if (keycode == KEY_S)
		w->pan_y -= 10;
	if (keycode == KEY_A)
		w->pan_x += 10;
	if (keycode == KEY_D)
		w->pan_x -= 10;
	scale_image(w);
	return (0);
}

void	rotate(t_window *w)
{
	t_matrix	*scaled;
	t_matrix	*m;
	t_matrix	*tf;

	clear_canva(w);
	tf = w->tf(w->orient);
	scaled = get_scale_mtx(w->curr_scale_x, w->curr_scale_y,
			0.4 * w->curr_scale_z);
	m = mult_mat(scaled, tf);
	get_figure_center(w, m, &(w->pan_x), &(w->pan_y));
	paint_canva_x(w, m, w->pan_x, w->pan_y);
	paint_canva_y(w, m, w->pan_x, w->pan_y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	free_matrix(scaled);
	free_matrix(m);
	free_matrix(tf);
}

void	change_view(t_window *w)
{
	static int	i;

	if (i % 2 == 0)
		w->tf = get_dimetric_mtx_tf;
	else
		w->tf = get_isometric_mtx_tf;
	i++;
	scale_image(w);
}
