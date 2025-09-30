#include "fdf.h"

int	key_press_event(int keycode, t_window *t_wind)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(t_wind->mlx, t_wind->win);
		exit(0);
	}
	return (0);
}

void	fdf_usage(void)
{
	ft_printf("\t\t\tFdf program usage:\n");
	ft_printf("\t\t\t./fdf <map_file>.fdf\n");
}

int	main(int argc, char **argv)
{
	t_window	wind;
	int			fd;
	t_point		*p;
	t_list		*l;

	wind.lpts = NULL;
	if (argc < 2)
	{
		fdf_usage();
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd < 3)
	{
		ft_printf("Error opening file\n");
		return (1);
	}
	if(!read_points(argv[1], &wind))
	{
		ft_printf("File cannot be loaded\n");
		exit(0);
	}
	l = wind.lpts;
	while (l)
	{
		p = l->content;
		ft_printf("x: %d y: %d z: %d\n", p->x, p->y, p->z);
		l = l->next;
	}
	ft_lstclear(&wind.lpts, free_points);
	// create_window(&wind, 1280, 720);
	// img.img = mlx_new_image(wind.mlx, wind.width, wind.height);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// &img.endian);
	// draw_circle(200, &img, &wind);
	// mlx_put_image_to_window(wind.mlx, wind.win, img.img, 0, 0);
	// mlx_hook(wind.win, 2, 1L<<0, key_press_event, &wind);
	// mlx_loop(wind.mlx);
}
