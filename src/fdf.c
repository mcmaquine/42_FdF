/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:40:18 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/06 20:07:52 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	fdf_usage(void)
{
	ft_printf("\t\t\tFdf program usage:\n");
	ft_printf("\t\t\t./fdf <map_file>.fdf\n");
}

int	file_input_validations(t_window *w, int argc, char **argv)
{
	int	fd;

	w->lpts = NULL;
	if (argc < 2)
	{
		fdf_usage();
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd < 3)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	if (!read_points(argv[1], w))
	{
		ft_printf("File cannot be loaded\n");
		return (0);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_window	w;
	int	x;
	t_matrix	*m, *ms, *tf;

	w.height = 720;
	w.width = 1280;
	m = get_isometric_mtx_tf();
	ms = get_scale_mtx(10, 10, 10);
	tf = mult_mat(ms, m);
	file_input_validations(&w, argc, argv);
	x = get_max_scalings(&w, tf);
	ft_printf("Scaling x: %d\n", x);
	ft_lstclear(&(w.lpts), free_points);
	free_matrix(m);
	free_matrix(ms);
	free_matrix(tf);
}*/

static void	start_draw(t_window *w)
{
	t_matrix	*scaled;
	t_matrix	*m;
	int			x;
	int			y;

	w->current_tf = get_isometric_mtx_tf();
	w->curr_scale = 10.0;
	scaled = get_scale_mtx(w->curr_scale,w->curr_scale, w->curr_scale);
	m = mult_mat(scaled, w->current_tf);
	get_figure_center(w, m, &x, &y);
	w->pan_x = x;
	w->pan_y = y;
	paint_canva_x(w, m, x, y);
	paint_canva_y(w, m, x, y);
	mlx_put_image_to_window(w->mlx, w->win, w->canva.img, 0, 0);
	free_matrix(scaled);
	free_matrix(m);
}

int	main(int argc, char **argv)
{
	t_window	wind;
	int			valid;

	valid = file_input_validations(&wind, argc, argv);
	if (!valid)
		return (0);
	create_window(&wind, 1280, 720);
	wind.canva.img = mlx_new_image(wind.mlx, wind.width, wind.height);
	wind.canva.addr = mlx_get_data_addr(wind.canva.img,
			&wind.canva.bits_per_pixel, &wind.canva.line_length,
			&wind.canva.endian);
	start_draw(&wind);
	mlx_hook(wind.win, 2, 1L << 0, key_press_event, &wind);
	mlx_hook(wind.win, 17, 0, on_close, &wind);
	mlx_mouse_hook(wind.win, mouse_hook, &wind);
	mlx_loop(wind.mlx);
}
