/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_events_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:57:35 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/09 10:27:39 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

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