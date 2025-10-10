/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:40:18 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/10 16:07:23 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_usage(void)
{
	ft_printf("\t\t\tFdf program usage:\n");
	ft_printf("\t\t\t./fdf <map_file>.fdf\n");
	return (0);
}

int	file_input_validations(t_window *w, int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		return (fdf_usage());
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
	{
		close(fd);
		ft_printf("Error opening file\n");
		return (0);
	}
	else
	{
		w->data.ordinate = 0;
		w->data.abscissa = validate_file(fd, &(w->data.ordinate));
		if (!w->data.abscissa)
		{
			ft_printf("File cannot be loaded\n");
			return (0);
		}
		else
			read_points(argv[1], w);
	}
	return (1);
}
/*
int	main(int argc, char **argv)
{
	t_window	w;
	t_matrix	*m;
	// t_matrix	*tf;
	// t_matrix	*ms;

	w.height = 720;
	w.width = 1280;
	m = get_rotate_mtx_x(1);
	// ms = get_scale_mtx(10, 10, 10);
	//tf = mult_mat(ms, m);
	file_input_validations(&w, argc, argv);
	// ft_printf("%X", set_color(0, 0, 0, 0xFF));
	free_data(&w);
	free_matrix(m);
	// free_matrix(ms);
	//free_matrix(tf);
}*/


void	start_draw(t_window *w)
{
	t_matrix	*scaled;
	t_matrix	*m;

	w->current_tf = get_isometric_mtx_tf();
	w->curr_scale = 10.0;
	scaled = get_scale_mtx(w->curr_scale,w->curr_scale, w->curr_scale);
	m = mult_mat(scaled, w->current_tf);
	get_figure_center(w, m, &(w->pan_x), &(w->pan_y));
	paint_canva_x(w, m, w->pan_x, w->pan_y);
	// paint_canva_y(w, m, w->pan_x, w->pan_y);
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
