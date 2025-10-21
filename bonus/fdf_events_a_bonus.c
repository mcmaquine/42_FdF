/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:57:35 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/20 20:36:17 by mmaquine         ###   ########.fr       */
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

void	rotate(t_window *w, double step)
{
	t_matrix	*scaled;
	t_matrix	*m;

	clear_canva(w);
	free_matrix(w->current_tf);
	w->current_tf = get_isometric_mtx_tf(step);
	scaled = get_scale_mtx(w->curr_scale_x, w->curr_scale_y, 
			0.4 * w->curr_scale_z);
	m = mult_mat(scaled, w->current_tf);
	get_figure_center(w, m, &(w->pan_x), &(w->pan_y));
	paint_canva_x(w, m, w->pan_x, w->pan_y);
	paint_canva_y(w, m, w->pan_x, w->pan_y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	free_matrix(scaled);
	free_matrix(m);
}
