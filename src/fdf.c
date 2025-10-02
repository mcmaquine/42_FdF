/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:40:18 by mmaquine          #+#    #+#             */
/*   Updated: 2025/10/02 17:39:47 by mmaquine         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_window	w;

	file_input_validations(&w, argc, argv);
	get_max_scalings(&w);
	ft_lstclear(&(w.lpts), free_points);
}
/*
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
	paint_canva(&wind);
	mlx_put_image_to_window(wind.mlx, wind.win, wind.canva.img, 0, 0);
	mlx_hook(wind.win, 2, 1L << 0, key_press_event, &wind);
	mlx_hook(wind.win, 17, 0, on_close, &wind);
	mlx_loop(wind.mlx);
}*/
