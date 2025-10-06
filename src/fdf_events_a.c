/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:57:35 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 20:06:39 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

int	pan_event(int keycode, t_window *w)
{
	clear_canva(w);
	if (keycode == KEY_W)
		w->pan_y -= w->pan_y * w->curr_scale;
	if (keycode == KEY_S)
		w->pan_y += w->pan_y * w->curr_scale;
	if (keycode == KEY_A)
		w->pan_x -= w->pan_x * w->curr_scale;
	if (keycode == KEY_D)
		w->pan_x += w->pan_x * w->curr_scale;
	paint_canva_x(w, w->current_tf, w->pan_x, w->pan_y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	return (0);
}