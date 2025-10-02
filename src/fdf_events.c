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

static void	free_memory(t_window *w)
{
	ft_lstclear(&(w->lpts), free_points);
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
