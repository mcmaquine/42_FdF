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

int	main(void)
{
	t_window	wind;
	t_data		img;

	create_window(&wind, 1280, 720);
	img.img = mlx_new_image(wind.mlx, wind.width, wind.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	&img.endian);
	draw_circle(200, &img, &wind);
	mlx_put_image_to_window(wind.mlx, wind.win, img.img, 0, 0);
	mlx_hook(wind.win, 2, 1L<<0, key_press_event, &wind);
	mlx_loop(wind.mlx);
}
